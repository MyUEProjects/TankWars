// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAimComponent.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Executed at start of game
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AimComponent = GetControlledTank()->FindComponentByClass<UTankAimComponent>();
	if (AimComponent)
		FoundAimingComponent(AimComponent);
	else
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Can't Find Aiming Component"))

	auto PossessedTank = GetControlledTank();
	if (!(PossessedTank))
		return;
	PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnTankDeath);
}

//Executed every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();

}

void ATankPlayerController::AimAtCrosshair()
{
	if (!(GetControlledTank()))		//In case no tank, don't actually do anything
		return; 
		
	if (GetSightHitRayLocation(HitLocation))
	{
		AimComponent->AimAt(HitLocation,LaunchSpeed);
	}
}

bool ATankPlayerController::GetSightHitRayLocation(FVector &HitLocation)
{
	//Get Position of Trigger on the screen
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX*CrossHairXLocation, ViewPortSizeY*CrossHairYLocation);

	//Get Screen Look Direction(we don't need the location)
	FVector CameraWorldLocation, CameraLookDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, CameraLookDirection))
	{
		//Get Hit Location and set it
		return GetVectorHitLocation(CameraLookDirection, HitLocation);

	}
	

	
	return false;
}

bool ATankPlayerController::GetVectorHitLocation(FVector CameraLookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + CameraLookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Camera))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to line Trace"));
		return false;
	}
}

void ATankPlayerController::OnTankDeath()
{
	StartSpectatingOnly();
}
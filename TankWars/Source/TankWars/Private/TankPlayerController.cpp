// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "Tank.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Executed at start of game
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank : %s"),*ControlledTank->GetName());
	}
	
}

//Executed every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();

}

void ATankPlayerController::AimAtCrosshair()
{
	if (GetControlledTank() == NULL)		//In case no tank, don't actually do anything
		return; 
		
	if (GetSightHitRayLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightHitRayLocation(FVector &HitLocation)
{
	//Get Position of Trigger on the screen
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreentLocation = FVector2D(ViewPortSizeX*CrossHairXLocation, ViewPortSizeY*CrossHairYLocation);

	//Get Screen Look Direction(we don't need the location)
	FVector CameraWorldLocation, CameraLookDirection;
	if (DeprojectScreenPositionToWorld(ScreentLocation.X, ScreentLocation.Y, CameraWorldLocation, CameraLookDirection))
	{
		//Get Hit Location and set it
		GetVectorHitLocation(CameraLookDirection, HitLocation);
		return true;
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Unable to Get Look Direction"))

		return false;
}

bool ATankPlayerController::GetVectorHitLocation(FVector CameraLookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + CameraLookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
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
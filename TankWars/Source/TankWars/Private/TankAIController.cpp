// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetHitLocation(HitLocation);
		GetControlledTank()->AimAt(HitLocation);
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto FPController =  GetWorld()->GetFirstPlayerController()->GetPawn();
	if (FPController)
		return Cast<ATank>(FPController);
	else
		return NULL;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Error : No Tank found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank : %s"), *PlayerTank->GetName());
	}

}

void ATankAIController::GetHitLocation(FVector &HitLocation)
{
	HitLocation = GetPlayerTank()->GetActorLocation();
}
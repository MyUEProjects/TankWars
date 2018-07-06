// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankAimComponent.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	AimComponent = ControlledTank->FindComponentByClass<UTankAimComponent>();
	if (ensure(PlayerTank) && ensure(ControlledTank))
	{
		MoveToActor(PlayerTank, MinDistanceFromPlayer);
		AimComponent->AimAt(PlayerTank->GetActorLocation(),LaunchSpeed);
		AimComponent->Fire();
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}


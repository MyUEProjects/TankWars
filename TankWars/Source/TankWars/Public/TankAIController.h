// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKWARS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	//Variables
	FVector HitLocation;

	//What happens when the game begins
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	void GetHitLocation(FVector &HitLocation);
};

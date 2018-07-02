// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

/**
 * 
 */
class ATank;
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

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinDistanceFromPlayer = 3000;

};

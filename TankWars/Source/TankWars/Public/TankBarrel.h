// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class TANKWARS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		void Elevate(float RelativeSpeed);
	
private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreePerSecond = 10;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDegrees = 45;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDegrees = -10;

};

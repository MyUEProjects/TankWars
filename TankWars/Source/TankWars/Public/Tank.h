// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Tank.generated.h"


class AProjectile;
class UTankMovementComponent;
class UTankAimComponent;

UCLASS()
class TANKWARS_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
	UPROPERTY(BlueprintReadOnly)
		UTankAimComponent *TankAimComponent = nullptr;

public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable)
		void Fire();

};

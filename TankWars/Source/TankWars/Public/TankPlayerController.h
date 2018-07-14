// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"


class ATank;
class UTankAimComponent;

/**
*
*/
UCLASS()
class TANKWARS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
		//Variables for Crosshair position
		UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;
		UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.333;
		
		//Variables for Line Trace
		UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.0;
		FVector HitLocation;

		
		//Inherited Functions
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		
		//My own functions
		
		//All functions below are used to get the AimAtCrosshair working
		void AimAtCrosshair();
		bool GetSightHitRayLocation(FVector &HitLocation);
		bool GetVectorHitLocation(FVector CameraLookDirection, FVector &HitLocation) const;

		UTankAimComponent *AimComponent;
		float LaunchSpeed = 4000;

protected:
	UFUNCTION(BlueprintCallable,Category = "Setup")
		ATank * GetControlledTank() const;
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimComponent *AimingComponentReference);

public:
	UFUNCTION()
		void OnTankDeath();
};

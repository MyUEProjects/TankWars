// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimComponent.generated.h"

//Enumerator consisting of all states
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKWARS_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	


	//Functions to move the Barrel and Turret
	void MoveBarrelTowards(FVector AimDirection);
	
	UTankBarrel *Barrel;
	UTankTurret *Turret;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeinSeconds = 3;
	float LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Aiming;



public:
	// Default Constructor
	UTankAimComponent();
	void AimAt(FVector HitLocation,float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();
	
};

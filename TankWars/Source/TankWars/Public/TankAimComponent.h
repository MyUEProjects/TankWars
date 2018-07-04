// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimComponent.generated.h"

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
	// Sets default values for this component's properties
	UTankAimComponent();
	void MoveBarrelTowards(FRotator DeltaRotation);
	void MoveTurretTowards(FRotator DeltaRotation);
	
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
	void AimAt(FVector HitLocation,float LaunchSpeed);
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);

	void SetBarrelComponent(UTankBarrel *BarrelToSet);
	void SetTurretComponent(UTankTurret *TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();
	
};

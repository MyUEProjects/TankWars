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
	Locked,
	OutOfBullets
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKWARS_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	//Functions to move the Barrel and Turret
	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();
	
	UTankBarrel *Barrel;
	UTankTurret *Turret;

	FRotator AimDiff;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeinSeconds = 3;
	float LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	int NumberOfBullets = 3;

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
	
	UFUNCTION(BlueprintCallable, Category = "Firing")
		int GetNumberOfBullets();
	EFiringState GetState() const;
};

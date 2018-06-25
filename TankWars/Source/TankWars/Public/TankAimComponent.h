// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimComponent.generated.h"

class UTankBarrel;
class UTankTurret;
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
public:
	void AimAt(FVector HitLocation,float LaunchSpeed);
	void SetBarrelComponent(UTankBarrel *BarrelToSet);
	void SetTurretComponent(UTankTurret *TurretToSet);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{
	if (!Barrel || !Turret)
		return;
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
		FRotator AimRotation = AimDirection.Rotation();
		FRotator DeltaRotation = AimRotation - BarrelRotation;
		MoveBarrelTowards(DeltaRotation);
		MoveTurretTowards(DeltaRotation);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Unable to Suggest Velocity"));

	
}

//Setters
void UTankAimComponent::SetBarrelComponent(UTankBarrel *BarrelToSet)
{
	Barrel = BarrelToSet;
}
void UTankAimComponent::SetTurretComponent(UTankTurret *TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimComponent::MoveBarrelTowards(FRotator DeltaRotation)
{

	Barrel->Elevate(DeltaRotation.Pitch); //TODO Magic Number
}

void UTankAimComponent::MoveTurretTowards(FRotator DeltaRotation)
{
	Turret->Rotate(DeltaRotation.Yaw);
}
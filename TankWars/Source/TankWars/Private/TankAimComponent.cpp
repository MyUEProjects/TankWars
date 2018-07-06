// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

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
	if (!ensure(Barrel && Turret))
		return;
		
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Unable to Suggest Velocity"));

	
}

void UTankAimComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;
	
	Barrel->Elevate(DeltaRotation.Pitch); 
	Turret->Rotate(DeltaRotation.Yaw);
}

void UTankAimComponent::Initialize(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet)
{
	if (!BarrelToSet || !TurretToSet)
		return;
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimComponent::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeinSeconds;
	if (Barrel && ProjectileBlueprint && isReloaded)
	{

		auto SpawnLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto SpawnRotation = Barrel->GetSocketRotation(FName("Projectile"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SpawnLocation, SpawnRotation);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Projectile.generated.h"

UCLASS()
class TANKWARS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
private:
	UProjectileMovementComponent *ProjectileMovement;
	UPROPERTY(VisibleAnywhere,Category = "Components")
		UStaticMeshComponent *CollisionMesh;
	UPROPERTY(VisibleAnywhere,Category = "Components")
		UParticleSystemComponent *LaunchBlast;


public:	
	// Constructor
	AProjectile();

	void LaunchProjectile(float Speed);

};

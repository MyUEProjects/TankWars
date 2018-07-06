// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class TANKWARS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
private:
	UProjectileMovementComponent *ProjectileMovement;


public:	
	// Constructor
	AProjectile();

	void LaunchProjectile(float Speed);

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Projectile.generated.h"

UCLASS()
class TANKWARS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
private:
	UProjectileMovementComponent *ProjectileMovement;
	UPROPERTY(VisibleAnywhere,Category = "Components")
		UStaticMeshComponent *CollisionMesh = nullptr;
	UPROPERTY(VisibleAnywhere,Category = "Components")
		UParticleSystemComponent *LaunchBlast = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent *ImpactBlast = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		URadialForceComponent *ExplosionForce = nullptr;
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float DestroyTimer = 10.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float DamageToApply = 20.0f;

	void OnTimerExpire();
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


public:
	// Constructor
	AProjectile();
	virtual void BeginPlay() override;
	void LaunchProjectile(float Speed);

};

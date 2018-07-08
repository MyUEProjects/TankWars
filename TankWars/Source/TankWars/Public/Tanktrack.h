// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKWARS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Movement)
		void Throttle(float ThrottleSpeed);
	
	//In Newtons
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxThrottleSpeed = 400000;

	UTankTrack();

	void ApplySidewaysForce();

private:
	virtual void BeginPlay() override;
	void DriveTrack();

	float CurrentThrottleSpeed = 0;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"
class UTankTrack;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKWARS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = InputAccept)
		void IntendToMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = InputAccept)
		void IntendToMoveRight(float Throw);
	UFUNCTION(BlueprintCallable, Category = InputAccept)
		void InitializeTrack(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet);
	
private:
	UTankTrack *LeftTrack = nullptr;
	UTankTrack *RightTrack = nullptr;
};

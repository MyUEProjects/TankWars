// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);


UCLASS()
class TANKWARS_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Constructor
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingHealth = 100;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 CurrentHealth;

public:
	FTankDelegate OnDeath;
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const & DamageEvent,class AController * EventInstigator,AActor * DamageCauser) override;
	
	UFUNCTION(BlueprintPure,Category = "Health")
		float GetHealthPercentage() const;

	virtual void BeginPlay() override;
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"




// Sets default values
ATank::ATank()
{
 	// Sets it so that this pawn cannot tick
	PrimaryActorTick.bCanEverTick = false;
	

}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	auto DamagetoApply = FMath::Clamp((int32)DamageAmount, 0, CurrentHealth);
	CurrentHealth = CurrentHealth - DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("My life is  : %i"), CurrentHealth)
	if (CurrentHealth <= 0)
		OnDeath.Broadcast();

	return DamagetoApply;

}

float ATank::GetHealthPercentage() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}
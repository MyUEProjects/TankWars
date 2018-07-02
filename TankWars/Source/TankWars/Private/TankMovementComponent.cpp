// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::IntendToMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack)
		return;

	LeftTrack->Throttle(Throw);
	RightTrack->Throttle(Throw);
}

void UTankMovementComponent::IntendToMoveRight(float Throw)
{
	if (!LeftTrack || !RightTrack)
		return;
	
	LeftTrack->Throttle(Throw);
	RightTrack->Throttle(-Throw);
}

void UTankMovementComponent::InitializeTrack(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
		return;

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto PlayerDirection = MoveVelocity.GetSafeNormal();

	float DirectionToMove = FVector::DotProduct(TankDirection, PlayerDirection);
	IntendToMoveForward(DirectionToMove);
	
	FVector RotationToMove = FVector::CrossProduct(TankDirection,PlayerDirection);
	IntendToMoveRight(RotationToMove.Z);
}
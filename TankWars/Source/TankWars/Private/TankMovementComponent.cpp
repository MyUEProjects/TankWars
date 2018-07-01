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
// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::Throttle(float ThrottleSpeed)
{
	FMath::Clamp(ThrottleSpeed, -1.0f, 1.0f);
	auto ForceApplied = GetForwardVector() * ThrottleSpeed * MaxThrottleSpeed;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



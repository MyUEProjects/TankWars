// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::Throttle(float ThrottleSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("%s moves at %f"), *GetName(), ThrottleSpeed);
	auto ForceApplied = GetForwardVector() * ThrottleSpeed * MaxThrottleSpeed;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



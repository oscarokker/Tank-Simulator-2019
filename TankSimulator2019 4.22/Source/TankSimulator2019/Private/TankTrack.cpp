// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h" // Must be first to include
#include "TankSimulator2019.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

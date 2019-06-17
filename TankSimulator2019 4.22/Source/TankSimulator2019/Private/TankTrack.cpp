// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h" // Must be first to include


void UTankTrack::SetThrottle(float Throttle)
{
	// TODO Clamp actual throttle value so player can't go too fast
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

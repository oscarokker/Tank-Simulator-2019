// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h" // Must be first to include
#include "TankTrack.h"
#include "TankSimulator2019.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

	LeftTrack->SetThrottle(Throw); 
	RightTrack->SetThrottle(Throw);

	// TODO prevent double-speed due to dual control use
}

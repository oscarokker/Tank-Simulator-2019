// Written by Oscar Rode

#include "TankTrack.h" // Must be first to include
#include "SprungWheel.h"
#include "TankSimulator2019.h"


UTankTrack::UTankTrack() // Constructor
{
	PrimaryComponentTick.bCanEverTick = false;
	SetNotifyRigidBodyCollision(true);
}


void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}


void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (ASprungWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}


TArray<class ASprungWheel*> UTankTrack::GetWheels() const
{
	USceneComponent::GetChildrenComponents(true, );
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h" // Must be last to include


/*
TankTrack is used to set maximum driving force, and to apply forces to the tank.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKSIMULATOR2019_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Max force per tracks in newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 300000; // Assume a 25 ton tank with a little over 1g acceleration
};
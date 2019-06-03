// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h" // Must be last to include


UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKSIMULATOR2019_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// 1 is max upward speed, and -1 is max downward speed
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 30;
};

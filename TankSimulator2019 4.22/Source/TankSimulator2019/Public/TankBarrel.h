// Written by Oscar Rode

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h" // Must be last to include


UCLASS(meta = (BlueprintSpawnableComponent))
class TANKSIMULATOR2019_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// 1 is max upward speed, and -1 is max downward speed
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 12;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 40;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0;
};

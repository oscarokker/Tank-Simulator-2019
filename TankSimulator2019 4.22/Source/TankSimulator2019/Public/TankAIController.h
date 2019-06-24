// Written by Oscar Rode

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h" // Must be last to include


UCLASS()
class TANKSIMULATOR2019_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// How close the AI Tank can get
	float AcceptanceRadius = 3000;
};

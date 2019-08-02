// Written by Oscar Rode

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h" // Must be last to include


/**
 * Controller component of Tank AI
 */
UCLASS()
class TANKSIMULATOR2019_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close the AI Tank can get
	UPROPERTY(EditDefaultsOnly, Category = "Behavior")
	float AcceptanceRadius = 8000;
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};

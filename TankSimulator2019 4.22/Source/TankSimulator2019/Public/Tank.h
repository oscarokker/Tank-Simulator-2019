// Written by Oscar Rode

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Must be last to include


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);
UCLASS()
class TANKSIMULATOR2019_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Called by engine when damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// Return current health as a percentage between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;

private:
	ATank(); // Constructor

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 3;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth; // Set in BeginPlay
};

// Written by Oscar Rode

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be last to include


// Forward declarations
class UTankAimingComponent;

/**
 * Responsible helping the player to aim
 */
UCLASS()
class TANKSIMULATOR2019_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Start the barrel moving toward where the crosshair intersects the world
	void AimTowardCrosshair();

	// Return an OUT parameter that is true if landscape is hit
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
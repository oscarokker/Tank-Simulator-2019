// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be last to include


UCLASS()
class TANKSIMULATOR2019_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	// Start the barrel moving toward where the crosshair intersects the world
	void AimTowardCrosshair();

	// Return an OUT parameter that is true if landscape is hit
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.5;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};

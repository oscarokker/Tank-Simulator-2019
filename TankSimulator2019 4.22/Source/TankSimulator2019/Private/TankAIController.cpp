// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h" // Must be first to include
#include "Tank.h"
#include "TankSimulator2019.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Move toward the player
		MoveToActor(
			PlayerTank,
			AcceptanceRadius
		); // TODO Check if radius is in cm

		// Aim toward the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); // TODO Limit fire rate
	}
}

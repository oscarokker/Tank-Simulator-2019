// Written by Oscar Rode

#include "TankAIController.h" // Must be first to include
#include "TankSimulator2019.h"
#include "TankAimingComponent.h"

 
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) {return;}

	// Move toward the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO Check if radius is in cm

	// Aim toward the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire(); // TODO limit firing rate
	}
}

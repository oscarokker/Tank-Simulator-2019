// Written by Oscar Rode

#include "Tank.h" // Must be first to include
#include "TankSimulator2019.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}


void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for BP to BeginPlay to run

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}


void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) {return;}

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::Fire()
{
	if (!ensure(Barrel)) {return;} // TODO Fix ensure log

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSecounds;
	if (isReloaded)
	{
		// Spawn a projectile at the socket location of the barrel
		auto SocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto SocketRotation = Barrel->GetSocketRotation(FName("Projectile"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SocketLocation, SocketRotation);

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

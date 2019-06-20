// Written by Oscar Rode

#include "Tank.h" // Must be first to include
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankSimulator2019.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s NOTICE ME: Tank C++ Construct"), *TankName)
}


void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for BP to BeginPlay to run
}


void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) {return;}
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSecounds;

	if (!Barrel || !isReloaded) {return;}

	// Spawn a projectile at the socket location of the barrel
	auto SocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
	auto SocketRotation = Barrel->GetSocketRotation(FName("Projectile"));
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SocketLocation, SocketRotation);

	Projectile->LaunchProjectile(LaunchSpeed);

	LastFireTime = FPlatformTime::Seconds();
}

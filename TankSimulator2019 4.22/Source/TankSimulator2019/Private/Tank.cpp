// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h" // Must be first to include
#include "TankAimingComponent.h"
#include "TankSimulator2019.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}


void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}


void ATank::AimAt(FVector HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("AimAt in Tank.ccp runs"));
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

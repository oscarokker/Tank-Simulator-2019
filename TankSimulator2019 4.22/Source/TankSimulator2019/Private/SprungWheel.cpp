// Written by Oscar Rode

#include "SprungWheel.h" // Must be first to include
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "TankSimulator2019.h"


ASprungWheel::ASprungWheel() // Constructor
{
	PrimaryActorTick.bCanEverTick = true;

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	SetRootComponent(Mass);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Mass);

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass Wheel Constraint"));
	MassWheelConstraint->SetupAttachment(Mass);
}


// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

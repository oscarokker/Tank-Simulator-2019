// Written by Oscar Rode

#include "SprungWheel.h" // Must be first to include
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "TankSimulator2019.h"


ASprungWheel::ASprungWheel() // Constructor
{
	PrimaryActorTick.bCanEverTick = true;

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass Wheel Constraint"));
	SetRootComponent(MassWheelConstraint);

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	Mass->SetupAttachment(MassWheelConstraint);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);
}


// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	if (GetAttachParentActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not null :D"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Null ;-;"));
	}
}


void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

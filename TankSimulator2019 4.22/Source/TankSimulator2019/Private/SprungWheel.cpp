// Written by Oscar Rode

#include "SprungWheel.h" // Must be first to include
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "TankSimulator2019.h"


ASprungWheel::ASprungWheel() // Constructor
{
	PrimaryActorTick.bCanEverTick = true;

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass Wheel Constraint"));
	SetRootComponent(MassWheelConstraint);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);
}


// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraint();
}


void ASprungWheel::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	MassWheelConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Wheel, NAME_None);
}


void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

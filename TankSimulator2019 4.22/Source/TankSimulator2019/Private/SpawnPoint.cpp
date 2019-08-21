// Written by Oscar Rode

#include "SpawnPoint.h"
#include "TankSimulator2019.h"


USpawnPoint::USpawnPoint() // Constructor
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	auto NewActor = GetWorld()->SpawnActor<AActor>(SpawnClass);
	if (!NewActor) {return;}
	NewActor->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

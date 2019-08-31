// Written by Oscar Rode

#include "SpawnPoint.h"
#include "TankTrack.h"
#include "Kismet/GameplayStatics.h"
#include "TankSimulator2019.h"


USpawnPoint::USpawnPoint() // Constructor
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	auto NewActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, GetComponentTransform());
	if (!NewActor) { return; }
	NewActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	UGameplayStatics::FinishSpawningActor(NewActor, GetComponentTransform());
}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


TArray<class ASprungWheel*> USpawnPoint::GetWheels() const
{
	TankTrack.GetWheels()
}

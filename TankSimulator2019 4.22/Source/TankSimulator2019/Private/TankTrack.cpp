// Written by Oscar Rode

#include "TankTrack.h" // Must be first to include
#include "TankSimulator2019.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}


void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("I'm hit, I'm hit!"))
}


void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Work-out the required acceleration in this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways for (F = m * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // 2 tank tracks
	TankRoot->AddForce(CorrectionForce);
}


void UTankTrack::SetThrottle(float Throttle)
{
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

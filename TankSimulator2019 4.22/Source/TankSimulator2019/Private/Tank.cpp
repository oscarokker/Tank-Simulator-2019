// Written by Oscar Rode

#include "Tank.h" // Must be first to include
#include "TankSimulator2019.h"


float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}


ATank::ATank() // Constructor
{
	PrimaryActorTick.bCanEverTick = false;
}


float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("DamagePoints = %i, DamageToApply = %i"), DamagePoints, DamageToApply)

	return DamageToApply;
}

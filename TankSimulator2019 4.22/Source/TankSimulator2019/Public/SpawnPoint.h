// Written by Oscar Rode

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpawnPoint.generated.h" // Must be last to include


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TANKSIMULATOR2019_API USpawnPoint : public USceneComponent
{
	GENERATED_BODY()

public:	
	USpawnPoint(); // Constructor

	virtual void TickComponent(
		float DeltaTime,
		ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;

	AActor* GetSpawnedActor() const { return SpawnedActor; }

protected:
	virtual void BeginPlay() override;

private:
	// Config
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AActor> SpawnClass;

	UPROPERTY()
	AActor* SpawnedActor;
};

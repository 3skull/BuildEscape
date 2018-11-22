// Who cares 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

#define  Out
// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

	if (!Owner) {
		UE_LOG(LogTemp, Error, TEXT("No Owner Found for : %s"), *(GetOwner()->GetName()));
	}
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		OnOpenRequest.Broadcast();
	}
	else{
		OnCloseRequest.Broadcast();
	}
}



float UOpenDoor::GetTotalMassOfActorsOnPlate() 
{
	float TotalMass = 0.0f;
	TArray<AActor*> OverlappingActors;
	if (PressurePlate) {

		PressurePlate->GetOverlappingActors(OUT OverlappingActors);

		for (const AActor* Actor : OverlappingActors)
		{
			TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();

			UE_LOG(LogTemp, Warning, TEXT("Pressure Plate has %s"), *(Actor->GetName()));
		}
	}
	

	return TotalMass;
}


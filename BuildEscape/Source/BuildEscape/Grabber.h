// Who cares 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	


private:

	float Reach = 100.0f;
	
	UPhysicsHandleComponent*	PhysicsHandle = nullptr;
	UInputComponent*			InputComponent = nullptr;

	// Ray-cast and Grab
	void Grab();

	void Release();

	void FindPhysicsComponent();

	void SetupInputComponent();

	FHitResult GetFirstPhysicsBodyInReach() const;

	FVector GetReachLineEnd() const;

	FVector GetReachLineStart() const;
	
};

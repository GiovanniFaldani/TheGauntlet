// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Components/MoveUpAndDownComponent.h"

// Sets default values for this component's properties
UMoveUpAndDownComponent::UMoveUpAndDownComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveUpAndDownComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(GetOwner()))
	{
		// Get first static mesh component that has the desired tag
		MeshToMove = Cast<UStaticMeshComponent>(GetOwner()->GetComponentsByTag(UStaticMeshComponent::StaticClass(), TagToSearch)[0]);
		if (!IsValid(MeshToMove))
		{
			UE_LOG(LogTemp, Error, TEXT("Owner does not possess a Static Mesh Component!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Owner not found!"));
	}

	
}


// Called every frame
void UMoveUpAndDownComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float NewZ = MovementAmplitude * FMath::Sin(ElapsedTime * MoveSpeed);

	if (IsValid(MeshToMove))
	{
		FVector CurrentLocation = MeshToMove->GetRelativeLocation();
		CurrentLocation.Z = NewZ;
		MeshToMove->SetRelativeLocation(CurrentLocation);

		ElapsedTime += DeltaTime;

		if (ElapsedTime * MoveSpeed > 2 * PI)
		{
			ElapsedTime = 0.0f;
		}
	}
}


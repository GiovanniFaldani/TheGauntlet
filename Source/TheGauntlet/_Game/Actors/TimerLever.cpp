// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/TimerLever.h"

// Sets default values
ATimerLever::ATimerLever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add switch mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ATimerLever::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimerLever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimerLever::ActivateLever()
{
	// TODO change switch color to green
	onLeverPull.ExecuteIfBound();
	bIsActive = true;

	Mesh->SetMaterial(0, GreenMaterial);

	// Start timer
	GetWorld()->GetTimerManager().SetTimer(
		RespawnTimer,
		this,
		&ATimerLever::DeactivateLever,
		LeverTimer,
		false
	);
}

void ATimerLever::DeactivateLever()
{
	// TODO change switch color to red
	onLeverUndo.ExecuteIfBound();
	bIsActive = false;

	Mesh->SetMaterial(0, RedMaterial);
}

void ATimerLever::Interact_Implementation()
{
	ActivateLever();
}


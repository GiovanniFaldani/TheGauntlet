// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/TimerLever.h"

// Sets default values
ATimerLever::ATimerLever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	// TODO move lever in world
	onLeverPull.ExecuteIfBound();
}

void ATimerLever::DeactivateLever()
{
	// TODO move lever in world back
	onLeverUndo.ExecuteIfBound();
}

void ATimerLever::Interact_Implementation()
{
	if (bIsActive) 
	{
		DeactivateLever();
	}
	else
	{
		ActivateLever();
	}
}


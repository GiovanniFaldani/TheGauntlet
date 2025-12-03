// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/TimerDoor.h"
#include "TimerLever.h"

// Sets default values
ATimerDoor::ATimerDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Build components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));

}

// Called when the game starts or when spawned
void ATimerDoor::BeginPlay()
{
	Super::BeginPlay();
	
	// TODO attach to lever delegates
}

// Called every frame
void ATimerDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimerDoor::Deactivate()
{

}

void ATimerDoor::Activate()
{

}


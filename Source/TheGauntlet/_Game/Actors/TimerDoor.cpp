// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/TimerDoor.h"
#include "Kismet/GameplayStatics.h"
#include "../CPP_PlayerController.h"

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

	// Get lever reference
	if (IsValid(LeverReference))
	{
		LeverReference->onLeverPull.BindUObject(this, &ATimerDoor::Deactivate);
		LeverReference->onLeverUndo.BindUObject(this, &ATimerDoor::Activate);
	}
	
}

// Called every frame
void ATimerDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimerDoor::Deactivate()
{
	bIsActive = false;

	SetActorHiddenInGame(!bIsActive);
	SetActorEnableCollision(bIsActive);
	SetActorTickEnabled(bIsActive);

	// Start timer
	GetWorld()->GetTimerManager().SetTimer(
		RespawnTimer,
		this,
		&ATimerDoor::Activate,
		DoorTimer,
		false
	);

	ACPP_PlayerController* PlayerController = Cast<ACPP_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (!IsValid(PlayerController)) return;

	PlayerController->PublishUIMessage(TEXT("Deactivated timed red door!"));
}

void ATimerDoor::Activate()
{
	bIsActive = true;

	SetActorHiddenInGame(!bIsActive);
	SetActorEnableCollision(bIsActive);
	SetActorTickEnabled(bIsActive);

	ACPP_PlayerController* PlayerController = Cast<ACPP_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (!IsValid(PlayerController)) return;

	PlayerController->PublishUIMessage(TEXT("Respawned timed red door!"));
}


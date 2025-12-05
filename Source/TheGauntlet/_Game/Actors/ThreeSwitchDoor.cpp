// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/ThreeSwitchDoor.h"
#include "Kismet/GameplayStatics.h"
#include "../CPP_PlayerController.h"

// Sets default values
AThreeSwitchDoor::AThreeSwitchDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	int Count = (int)ESwitchIndex::Count;
	SwitchStatus.Init(false, Count);

}

// Called when the game starts or when spawned
void AThreeSwitchDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThreeSwitchDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AThreeSwitchDoor::Deactivate()
{
	bIsActive = false;

	SetActorHiddenInGame(!bIsActive);
	SetActorEnableCollision(bIsActive);
	SetActorTickEnabled(bIsActive);

	ACPP_PlayerController* PlayerController = Cast<ACPP_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (!IsValid(PlayerController)) return;

	PlayerController->PublishUIMessage(TEXT("Deactivated blue door!"));
}

void AThreeSwitchDoor::Activate()
{
	bIsActive = true;

	SetActorHiddenInGame(!bIsActive);
	SetActorEnableCollision(bIsActive);
	SetActorTickEnabled(bIsActive);
}

void AThreeSwitchDoor::SetSwitchTo(bool Value, ESwitchIndex Index)
{
	SwitchStatus[(int)Index] = Value;

	// check if all switches are active
	if (CheckSwitches()) 
	{
		Deactivate();
	}
	else
	{
		Activate();
	}

}

bool AThreeSwitchDoor::CheckSwitches()
{
	for (bool& Value : SwitchStatus)
	{
		if (Value == false)	return false;
		else continue;
	}

	return true;
}


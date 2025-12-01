// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/Door.h"
#include "Kismet/GameplayStatics.h"
#include "../CPP_Character.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	// subscribe to player delegate
	UWorld* World = GetWorld();
	if (IsValid(World))
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
		if (IsValid(PlayerController))
		{
			ACPP_Character* PlayerCharacter = Cast<ACPP_Character>(PlayerController->GetCharacter());
			if (IsValid(PlayerCharacter))
			{
				PlayerCharacter->onKeyCollected.AddUObject(this, &ADoor::DestroyActor);
			}
		}
	}
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::DestroyActor()
{
	this->Destroy();
}


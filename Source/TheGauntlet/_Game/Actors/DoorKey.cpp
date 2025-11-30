// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/DoorKey.h"
#include "Kismet/GameplayStatics.h"
#include "../CPP_Character.h"

// Sets default values
ADoorKey::ADoorKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoorKey::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorKey::Interact_Implementation()
{
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(12, 1.0f, FColor::Blue, TEXT("Getting player..."));
	UWorld* World = GetWorld();
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);

	ACPP_Character* PlayerCharacter = Cast<ACPP_Character>(PlayerController->GetCharacter());
	if (IsValid(PlayerCharacter))
	{
		PlayerCharacter->SetKeyCollected(true);
		GEngine->AddOnScreenDebugMessage(40, 1.0f, FColor::Blue, TEXT("Collected Key"));
	}

	// TODO Destroy this actor
}


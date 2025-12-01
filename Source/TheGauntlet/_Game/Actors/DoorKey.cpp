// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/DoorKey.h"
#include "Kismet/GameplayStatics.h"
#include "../CPP_Character.h"

// Sets default values
ADoorKey::ADoorKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add up and down movement
	MovementComponent = CreateDefaultSubobject<UMoveUpAndDownComponent>(TEXT("MoveUpAndDown"));
}

// Called when the game starts or when spawned
void ADoorKey::BeginPlay()
{
	Super::BeginPlay();	

	// Subscribe to player delegate
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (IsValid(PlayerController))
	{
		ACPP_Character* PlayerCharacter = Cast<ACPP_Character>(PlayerController->GetCharacter());
		if (IsValid(PlayerCharacter))
		{
			PlayerCharacter->onKeyCollected.AddUObject(this, &ADoorKey::DestroyActor);
		}
	}
}

// Called every frame
void ADoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorKey::Interact_Implementation()
{
	check(GEngine != nullptr);
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (IsValid(PlayerController))
	{
		ACPP_Character* PlayerCharacter = Cast<ACPP_Character>(PlayerController->GetCharacter());
		if (IsValid(PlayerCharacter))
		{
			PlayerCharacter->SetKeyCollected(true);
			GEngine->AddOnScreenDebugMessage(40, 1.0f, FColor::Blue, TEXT("Collected Key"));
		}
	}
}

void ADoorKey::DestroyActor()
{
	// Subscribe to player delegate and destroy actor when collected
	this->Destroy();
}


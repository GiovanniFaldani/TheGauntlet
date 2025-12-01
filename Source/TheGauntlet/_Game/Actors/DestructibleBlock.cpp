// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/DestructibleBlock.h"
#include "Kismet/GameplayStatics.h"
#include "../CPP_Character.h"

// Sets default values
ADestructibleBlock::ADestructibleBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADestructibleBlock::BeginPlay()
{
	Super::BeginPlay();

	// Set health variable
	HP = MaxHP;
	
}

// Called every frame
void ADestructibleBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestructibleBlock::DestroyActor()
{
	this->Destroy();
}

void ADestructibleBlock::Interact_Implementation()
{
	// Get player damage
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if(IsValid(PlayerController))
	{
		ACPP_Character* PlayerCharacter = Cast<ACPP_Character>(PlayerController->GetCharacter());
		if (IsValid(PlayerCharacter))
		{
			IDamageable::Execute_ReceiveDamage(this, PlayerCharacter->GetDamage());
		}
	}
}

// TODO add timer or else it takes damage every frame
void ADestructibleBlock::ReceiveDamage_Implementation(float DamageReceived)
{
	check(GEngine);
	GEngine->AddOnScreenDebugMessage(17, 1.0f, FColor::Red, FString::Printf(TEXT("Dealt %f.2 damage to obstacle!"), DamageReceived));

	HP -= DamageReceived;
	if(HP <=0.f)
	{
		DestroyActor();
	}
}


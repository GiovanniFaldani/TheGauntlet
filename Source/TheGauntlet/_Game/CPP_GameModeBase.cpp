// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/CPP_GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_Character.h"

void ACPP_GameModeBase::BeginPlay()
{
	// Subscribe to player delegates
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if(IsValid(PlayerController))
	{
		ACPP_Character* PlayerCharacter = Cast<ACPP_Character>(PlayerController->GetCharacter());
		if (IsValid(PlayerCharacter))
		{
			PlayerCharacter->onGameOver.AddUObject(this, &ACPP_GameModeBase::GameOver);
			PlayerCharacter->onFallOutOfWorld.AddUObject(this, &ACPP_GameModeBase::PlayerFell);
			PlayerCharacter->onLevelComplete.AddUObject(this, &ACPP_GameModeBase::GameVictory);
		}
	}
	
}

void ACPP_GameModeBase::PlayerFell()
{
	// Player fell from map behavior, deal FallDamage via the IDamageable interface and respawn on PlayerStart

	// Get player 
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (IsValid(PlayerController))
	{
		ACPP_Character* PlayerCharacter = Cast<ACPP_Character>(PlayerController->GetCharacter());
		if (IsValid(PlayerCharacter) && PlayerCharacter->GetClass()->ImplementsInterface(UDamageable::StaticClass()))
		{
			// Call IDamageable method
			IDamageable::Execute_ReceiveDamage(PlayerCharacter, FallDamage);

			// TODO Respawn player on PlayerStart
		}
	}
}

void ACPP_GameModeBase::GameVictory()
{
	// Check for victory condition
}

void ACPP_GameModeBase::GameOver()
{
	// Check for game over condition
}

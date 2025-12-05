// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEGAUNTLET_API ACPP_PlayerController : public APlayerController
{
	GENERATED_BODY()

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

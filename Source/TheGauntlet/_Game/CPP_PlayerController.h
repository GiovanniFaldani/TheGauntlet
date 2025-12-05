// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_PlayerController.generated.h"

class UHUDWidget;

/**
 * 
 */
UCLASS()
class THEGAUNTLET_API ACPP_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// The class of the HUD to spawn (Assign this in BP_GauntletPlayerController)
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UHUDWidget> HUDWidgetClass;

	// The actual instance of the HUD
	UPROPERTY()
	TObjectPtr<UHUDWidget> HUDWidgetInstance;

public:
	// Print message to screen from anywhere
	UFUNCTION(BlueprintCallable, Category = "UI")
	void PublishUIMessage(FString Message);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void PlayerTick(float DeltaTime);

	// Helper to bind to the Pawn's delegates
	void BindToPawnDelegates(APawn* InPawn);

	// Callback when the Pawn broadcasts a health change
	UFUNCTION()
	void HandlePawnHealthChanged(float NewHealth, float MaxHealth);

	// Callback when the Pawn broadcasts interactable actor found
	UFUNCTION()
	void HandleInteractionMessage(bool Found);
};

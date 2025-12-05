// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/CPP_PlayerController.h"
#include "UI/HUDWidget.h"
#include "CPP_Character.h"
#include "Components/InteractionComponent.h"
#include "GameFramework/Character.h" 

void ACPP_PlayerController::BeginPlay()
{
	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UHUDWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance)
		{
			// Add to viewport (Standard UMG way) or use CommonUI's Root Layout if configured
			check(GEngine != nullptr);
			GEngine->AddOnScreenDebugMessage(39, 0.1f, FColor::Green, TEXT("Player Controller correct init"));
			HUDWidgetInstance->AddToViewport();
			FInputModeGameOnly GameInputMode;
			SetInputMode(GameInputMode);
			bShowMouseCursor = false;
		}
		else
		{
			check(GEngine != nullptr);
			GEngine->AddOnScreenDebugMessage(94, 0.1f, FColor::Green, TEXT("HUDWidget Instance not found"));
		}
	}
	else
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(97, 0.1f, FColor::Green, TEXT("HUDWidget Class not found"));
	}
}

void ACPP_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context BEFORE the character sets up input bindings
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (ACPP_Character* MyCharacter = Cast<ACPP_Character>(GetPawn()))
		{
			if (MyCharacter->GetInputMappingContext())
			{
				Subsystem->AddMappingContext(MyCharacter->GetInputMappingContext(), 0);
			}
		}
	}
}

// launches on Pawn posses (at level01 load in this case), use this to bind UI to player delegates
void ACPP_PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	BindToPawnDelegates(InPawn);
}

void ACPP_PlayerController::BindToPawnDelegates(APawn* InPawn)
{
	ACPP_Character* MyPlayer = Cast<ACPP_Character>(InPawn);
	if (IsValid(MyPlayer))
	{
		// Unbind first to prevent double binding
		MyPlayer->onHealthChanged.RemoveDynamic(this, &ACPP_PlayerController::HandlePawnHealthChanged);

		// Bind	delegate
		MyPlayer->onHealthChanged.AddDynamic(this, &ACPP_PlayerController::HandlePawnHealthChanged);

		// bind interaction component delegate
		UInteractionComponent* InteractComponent = Cast<UInteractionComponent>(MyPlayer->GetComponentByClass(UInteractionComponent::StaticClass()));
		if (IsValid(InteractComponent))
		{
			InteractComponent->onFindInteractable.BindUObject(this, &ACPP_PlayerController::HandleInteractionMessage, true);
			InteractComponent->onLoseInteractable.BindUObject(this, &ACPP_PlayerController::HandleInteractionMessage, false);
		}
	}
}

void ACPP_PlayerController::HandlePawnHealthChanged(float NewHealth, float MaxHealth)
{
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->UpdateHealth(NewHealth, MaxHealth);
	}
}

void ACPP_PlayerController::HandleInteractionMessage(bool Found)
{
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->SetInteractionMessageVisibility(Found);
	}
}

void ACPP_PlayerController::PublishUIMessage(FString Message)
{
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->DisplaySystemMessage(Message);
	}
}

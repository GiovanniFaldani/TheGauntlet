// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/UI/HUDWidget.h"
#include "CommonTextBlock.h"
#include "Components/ProgressBar.h"

void UHUDWidget::NativeConstruct()
{
	if (SystemMessageText)
	{
		SystemMessageText->SetText(FText::GetEmpty());
	}
}

void UHUDWidget::UpdateHealth(float CurrentHealth, float MaxHealth)
{
	// Update Health Bar
	if (HealthProgressBar && MaxHealth > 0.0f)
	{
		const float Percent = FMath::Clamp(CurrentHealth / MaxHealth, 0.0f, 1.0f);
		HealthProgressBar->SetPercent(Percent);
	}
}

void UHUDWidget::DisplaySystemMessage(FString Message)
{
	if (SystemMessageText)
	{
		SystemMessageText->SetText(FText::FromString(Message));
	}
}

//void UHUDWidget::SetInteractionMessageVisibility(bool Visible)
//{
//	InteractionPromptText->SetVisibility(Visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
//}



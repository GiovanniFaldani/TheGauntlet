// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 
#include "InputActionValue.h"
#include "CPP_Character.generated.h"

// Forward declarations for movement
class UInputMappingContext;
class UInputAction;
class UInputComponent;

// Delegate declarations
DECLARE_MULTICAST_DELEGATE(OnGameOver)
DECLARE_DELEGATE(OnInteract)

UCLASS()
class THEGAUNTLET_API ACPP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Character();

	OnGameOver onGameOver;
	OnInteract onInteract;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Player)
	float HP;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputMappingContext> FirstPersonContext;

	// Move Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> MoveAction;

	// Jump Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> JumpAction;

	// Interact Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> InteractAction;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles 2D Movement Input
	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category = Player)
	void OnInteract();

	UFUNCTION(BlueprintCallable, Category = Player)
	void ReceiveDamage(float Damage);

};

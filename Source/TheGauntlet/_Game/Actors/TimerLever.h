// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/Interactable.h"
#include "TimerLever.generated.h"

DECLARE_DELEGATE(OnLeverPull)
DECLARE_DELEGATE(OnLeverUndo)

UCLASS()
class THEGAUNTLET_API ATimerLever : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimerLever();

	// delegates
	OnLeverPull onLeverPull;
	OnLeverUndo onLeverUndo;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Lever")
	bool bIsActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Lever")
	float LeverTimer;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Timer Lever")
	FTimerHandle RespawnTimer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Lever")
	UMaterialInstance* GreenMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Lever")
	UMaterialInstance* RedMaterial;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Lever")
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Timer Lever")
	void ActivateLever();

	UFUNCTION(BlueprintCallable, Category = "Timer Lever")
	void DeactivateLever();

	virtual void Interact_Implementation() override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/Interactable.h"
#include "ThreeSwitchDoor.h"
#include "SingleSwitch.generated.h"

UCLASS()
class THEGAUNTLET_API ASingleSwitch : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASingleSwitch();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Single Switch")
	bool bIsActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Single Switch")
	ESwitchIndex SwitchIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Single Switch")
	AThreeSwitchDoor* Door;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Lever")
	UMaterialInstance* BlueMaterial;

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

	UFUNCTION(BlueprintCallable, Category = "Single Switch")
	void ActivateSwitch();

	UFUNCTION(BlueprintCallable, Category = "Single Switch")
	void DeactivateSwitch();

	virtual void Interact_Implementation() override;

};

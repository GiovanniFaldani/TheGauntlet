// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThreeSwitchDoor.generated.h"

UENUM(BlueprintType)
enum class ESwitchIndex : uint8 {
	FirstSwitch		UMETA(DisplayName = "First Switch"),
	SecondSwitch	UMETA(DisplayName = "Second Switch"),
	ThirdSwitch		UMETA(DisplayName = "Third Switch"),
	Count
};

UCLASS()
class THEGAUNTLET_API AThreeSwitchDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThreeSwitchDoor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Switch Door")
	bool bIsActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Switch Door")
	TArray<bool> SwitchStatus;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Switch Door")
	void Deactivate();

	UFUNCTION(BlueprintCallable, Category = "Switch Door")
	void Activate();

	void SetSwitchTo(bool Value, ESwitchIndex Index);

	bool CheckSwitches();

};

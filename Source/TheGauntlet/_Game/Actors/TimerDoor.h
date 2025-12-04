// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "TimerLever.h"
#include "Engine/TimerHandle.h"
#include "TimerDoor.generated.h"

UCLASS()
class THEGAUNTLET_API ATimerDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimerDoor();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Door")
	bool bIsActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Door")
	float DoorTimer;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Timer Door")
	FTimerHandle RespawnTimer;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Door")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Door")
	UBoxComponent* Collision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timer Door")
	ATimerLever* LeverReference;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Timer Door")
	void Deactivate();

	UFUNCTION(BlueprintCallable, Category = "Timer Door")
	void Activate();


};

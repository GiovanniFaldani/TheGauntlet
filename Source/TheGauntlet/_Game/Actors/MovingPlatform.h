// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class THEGAUNTLET_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();
	 
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Moving Platform")
	TArray<FVector> WayPoints{ };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Moving Platform")
	TArray<float> TravelTimes{ };

private:

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector StartPosition{ };

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	int CurrentIndex{ 1 };

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float PercentageComplete{ 0. };

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float ElapsedTime{ 0. };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MoveBetweenWaypoints(float DeltaTime);

};

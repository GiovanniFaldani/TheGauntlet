// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovingPlatformComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEGAUNTLET_API UMovingPlatformComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovingPlatformComponent();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Moving Platform")
	TArray<FVector> WayPoints;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Moving Platform")
	TArray<float> TravelTimes;

private:

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector StartPosition;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	int CurrentIndex;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float PercentageComplete;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float ElapsedTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void MoveBetweenWaypoints(float DeltaTime);

};

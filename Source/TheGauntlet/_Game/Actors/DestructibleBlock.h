// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/Interactable.h"
#include "../Interfaces/Damageable.h"
#include "DestructibleBlock.generated.h"

UCLASS()
class THEGAUNTLET_API ADestructibleBlock : public AActor, public IInteractable, public IDamageable
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Player)
	float MaxHP;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Player)
	float HP;
	
public:	
	// Sets default values for this actor's properties
	ADestructibleBlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DestroyActor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;

	virtual void ReceiveDamage_Implementation(float DamageReceived) override;

};

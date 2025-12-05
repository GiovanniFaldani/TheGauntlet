// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/Actors/SingleSwitch.h"

// Sets default values
ASingleSwitch::ASingleSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add switch mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ASingleSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASingleSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASingleSwitch::ActivateSwitch()
{
	bIsActive = true;
	Mesh->SetMaterial(0, BlueMaterial);
	Door->SetSwitchTo(bIsActive, SwitchIndex);

}

void ASingleSwitch::DeactivateSwitch()
{
	bIsActive = false;
	Mesh->SetMaterial(0, RedMaterial);
	Door->SetSwitchTo(bIsActive, SwitchIndex);
	
}

void ASingleSwitch::Interact_Implementation()
{
	
	if (bIsActive)
	{
		DeactivateSwitch();
	}
	else
	{
		ActivateSwitch();
	}
}


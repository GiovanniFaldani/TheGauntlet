// Fill out your copyright notice in the Description page of Project Settings.


#include "_Game/CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);  // First Person camera

	Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Arm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Arm->TargetArmLength = CameraDistance;
	Arm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	// tweak if necessary
	Arm->bEnableCameraLag = false; 
	Arm->CameraLagSpeed = 2;
	Arm->CameraLagMaxDistance = 1.5f;

	Arm->bEnableCameraRotationLag = false;
	Arm->CameraRotationLagSpeed = 4;
	Arm->CameraLagMaxTimeStep = 1;

	Camera->AttachToComponent(Arm, FAttachmentTransformRules::SnapToTargetNotIncludingScale, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	// Get the player controller for this character
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		// Get the enhanced input local player subsystem and add a new input mapping context to it
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
			FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);
			PlayerController->bShowMouseCursor = false;
		}
	}
	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using CPP_Character."));
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Check the UInputComponent passed to this function and cast it to an UEnhancedInputComponent
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Bind Movement Actions
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPP_Character::Move);

		// Bind Camera Actions
		EnhancedInputComponent->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ACPP_Character::MoveCamera);

		// Bind Jump Actions
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Bind Interact Action
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ACPP_Character::OnInteract);
	}

}

void ACPP_Character::Move(const FInputActionValue& Value) 
{
	const FVector2D MovementValue = Value.Get<FVector2D>();

	if (IsValid(Controller))
	{
		const FVector Right = Camera->GetRightVector();
		AddMovementInput(Right, MovementValue.X);

		// Add forward and back movement
		const FVector Forward = Camera->GetForwardVector();
		AddMovementInput(Forward, MovementValue.Y);

	}
}

void ACPP_Character::MoveCamera(const FInputActionValue& Value)
{
	const FVector2D MovementValue = Value.Get<FVector2D>();

	if (IsValid(Controller))
	{
		AddControllerYawInput(-MovementValue.X);
		AddControllerPitchInput(MovementValue.Y);
	}
}

void ACPP_Character::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, TEXT("Interact!"));
	onInteract.ExecuteIfBound();
}

void ACPP_Character::ReceiveDamage(float Damage)
{
	// TODO Game over check
}


// TODO Add Third Person camera control

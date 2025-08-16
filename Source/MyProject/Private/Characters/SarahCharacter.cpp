// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SarahCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ASarahCharacter::ASarahCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.0f;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);

}

// Called when the game starts or when spawned
void ASarahCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASarahCharacter::MoveForward(float Value)
{
	if (Controller !=nullptr && Value !=0.f)
	{
		//find out which way is forward
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
		
	}
	
}

void ASarahCharacter::MoveRight(float Value)
{
	if (Controller != nullptr && Value !=0.f)
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
		FVector Right = GetActorRightVector();
		AddMovementInput(Right, Value);
	}
	}
	
}

void ASarahCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
	
}

void ASarahCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

// Called every frame
void ASarahCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASarahCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &ASarahCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &ASarahCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &ASarahCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Mouse"), this, &ASarahCharacter::LookUp);
	

}


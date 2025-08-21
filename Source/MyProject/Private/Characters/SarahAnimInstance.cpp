// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SarahAnimInstance.h"
#include "Characters/SarahCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USarahAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	SarahCharacter= Cast<ASarahCharacter>(TryGetPawnOwner());
	if (SarahCharacter)
	{
		SarahCharacterMovement=SarahCharacter->GetCharacterMovement();
	}
}

void USarahAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (!SarahCharacter)
	{
		SarahCharacter = Cast<ASarahCharacter>(TryGetPawnOwner());
	}
	if (SarahCharacter)
	{
		SarahCharacterMovement = SarahCharacter->GetCharacterMovement();
	}
	if (SarahCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(SarahCharacterMovement->Velocity);
		IsFalling = SarahCharacterMovement->IsFalling();
	}
	else
	{
		GroundSpeed = 0.f;
	}
	
}

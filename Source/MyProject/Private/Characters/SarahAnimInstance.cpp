// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SarahAnimInstance.h"
#include "Characters/SarahCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void USarahAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	SarahCharacter= Cast<ASarahCharacter>(TryGetPawnOwner());
	if (SarahCharacter)
	{
		SarahCharacter->GetCharacterMovement();
	}
}

void USarahAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
}

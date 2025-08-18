// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SarahAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API USarahAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;
	UPROPERTY(BlueprintReadOnly)
	class ASarahCharacter* SarahCharacter;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	class UCharacterMovementComponent* SarahCharacterMovement;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;
};

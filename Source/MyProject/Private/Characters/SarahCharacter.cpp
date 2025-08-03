// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SarahCharacter.h"


// Sets default values
ASarahCharacter::ASarahCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
		
	}
	
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
	

}


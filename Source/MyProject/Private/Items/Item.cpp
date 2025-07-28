// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "MyProject/DebugMacros.h"
#include "DrawDebugHelpers.h"



// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	float DeltaZ = Amplitude *  FMath::Sin(RunningTime * Frequency);
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ), true);
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
	

}


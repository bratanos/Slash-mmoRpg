// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"



UCLASS()
class MYPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:
	AItem();
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Sine Parameters")
	float Amplitude = 0.25f; // Amplitude of the sine wave for vertical movement
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sine Parameters")
	float Frequency = 5.f; // Frequency of the sine wave for vertical movement

	UFUNCTION(BlueprintPure, Category="Sine Parameters")
	float TransformedSin();

	UFUNCTION(BlueprintPure, Category="Sine Parameters")
	float TransformedCos();
private :
	UPROPERTY(VisibleAnywhere)
	float RunningTime;

};

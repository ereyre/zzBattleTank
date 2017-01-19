// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Tank Barrel mouvement controller
 */
UCLASS( meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class ZZBATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 the max up speed
	void Elevate(float relativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerrSecond = 20.0f;  //To find

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40.0f;  // can be greater
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0.0f;  //beware of the rear of the hull 


	
};

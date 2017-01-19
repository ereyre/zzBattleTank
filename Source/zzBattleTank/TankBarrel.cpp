// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float relativeSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT(" Elevate called at speed %f "), *(&relativeSpeed));

	float clampedSpeed = FMath::Clamp<float>(relativeSpeed, -1.0, 1.0);


	float elevationChange = clampedSpeed * MaxDegreePerrSecond * GetWorld()->DeltaTimeSeconds;
	float rawNewElevation = RelativeRotation.Pitch + elevationChange;

	float newElevation = FMath::Clamp<float>(rawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(newElevation, 0, 0));


}
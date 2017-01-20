// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankTurret.h"




void UTankTurret::Rotate(float relativeSpeed) {

	//auto time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f : Tank turret should turn of %f"), time, relativeSpeed);
	
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, +1);
	
	auto RotationChange = relativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	
	//auto time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f : Tank turret should turn of %f"), time, Rotation);


	SetRelativeRotation(FRotator(0, Rotation, 0));




}
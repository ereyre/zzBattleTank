// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankMovementComponent.h"




void UTankMovementComponent::IntendMoveForward(float throttle)
{
	if (throttle != 0.0f) {
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f : Advance Throttle asked  %f"), time, throttle);
	}
	


}
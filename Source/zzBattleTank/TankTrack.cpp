// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankTrack.h"



void UTankTrack::SetThrottle(float throttle) {

	/*
	auto time = GetWorld()->GetTimeSeconds();
	auto name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%f :  %s - Throttle set to %f"), time, *name, throttle);
	*/

	// Clamp throttle value to avoid overdriving
	FVector forceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	FVector forceLocation = GetComponentLocation();

	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	tankRoot->AddForceAtLocation(forceApplied, forceLocation);

}

// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}



void UTankTrack::SetThrottle(float throttle) {

	// Clamp throttle value to avoid overdriving
	FVector forceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	FVector forceLocation = GetComponentLocation();

	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	tankRoot->AddForceAtLocation(forceApplied, forceLocation);

}



void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{

	UE_LOG(LogTemp, Warning, TEXT("I was here"));

}

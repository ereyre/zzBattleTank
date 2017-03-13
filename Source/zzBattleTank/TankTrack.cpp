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



void UTankTrack::CustomTick(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (true) return; //disabling the custom tick componeent
	
	//calculate the slippage speed
	auto slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Workout the required acceleration this fram to correct
	auto correctionAcceleration = -slippageSpeed / DeltaTime * GetRightVector();
	
	// Calculate and apply sideway for ( F = m a)
	auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto correctionForce = (tankRoot->GetMass() *correctionAcceleration) / 2;

	tankRoot->AddForce(correctionForce);
}



void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	UE_LOG(LogTemp, Warning, TEXT("Ping d'une des tracks"));

	//calculate the slippage speed
	auto slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Workout the required acceleration this fram to correct
	auto correctionAcceleration = -slippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideway for ( F = m a)
	auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto correctionForce = (tankRoot->GetMass() *correctionAcceleration) / 2;

	tankRoot->AddForce(correctionForce);
}


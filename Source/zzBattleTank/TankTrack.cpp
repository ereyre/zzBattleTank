// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankTrack.h"



UTankTrack::UTankTrack() {

	// will tick evry frame
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}



void UTankTrack::SetThrottle(float throttle) {

	// Clamp throttle value to avoid overdriving
	FVector forceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	FVector forceLocation = GetComponentLocation();

	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	tankRoot->AddForceAtLocation(forceApplied, forceLocation);

}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	UE_LOG(LogTemp, Warning, TEXT("Ping des chaines"));
}

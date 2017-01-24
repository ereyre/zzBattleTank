// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"




void UTankMovementComponent::IntendMoveForward(float throttle)
{
	/*if (throttle != 0.0f) {
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f : Advance Throttle asked  %f"), time, throttle);
	}*/
	if (!LeftTrack || !RightTrack) return;

	LeftTrack->SetThrottle(throttle);
	RightTrack->SetThrottle(throttle);

	// TODO prevent double-speed cause by using stick + shoulder button


}

void UTankMovementComponent::IntendTurnRight(float throttle)
{
	if (!LeftTrack || !RightTrack) return;

	LeftTrack->SetThrottle(throttle);
	RightTrack->SetThrottle(-throttle);

}

void UTankMovementComponent::Initialise(UTankTrack * leftTrack, UTankTrack * rightTrack)
{
	if (!leftTrack || !rightTrack) {
		UE_LOG(LogTemp, Error, TEXT("Tracks are missing into TankMovmentComponent"));
		return;
	}

	RightTrack = rightTrack;
	LeftTrack = leftTrack;


	
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// log name and vector
	auto name = GetOwner()->GetName();
	auto direction = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s Request directmove toward %s"), *name, *direction);

}

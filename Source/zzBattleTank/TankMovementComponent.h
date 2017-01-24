// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * REsponsible for driving the tanks tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ZZBATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	// Intend move forward /backward in flight by wire mode
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float throttle);
	
	// intend to rotate clockwise in flight by wire mode
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float throttle);

	// IKnitialise movement Compoenent and add tracks
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTrack* leftTrack, UTankTrack* rightTrack);

	//TODO check best protection



	/** path following: request new velocity */
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

		
private:
	UTankTrack* LeftTrack;
	UTankTrack* RightTrack;


};

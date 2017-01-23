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
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float throttle);

	// IKnitialise movement Compoenent and add tracks
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankTrack* leftTrack, UTankTrack* rightTrack);

		
private:
	UTankTrack* LeftTrack;
	UTankTrack* RightTrack;


};

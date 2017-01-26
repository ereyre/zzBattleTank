// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *  TankTrack is used to set maximum driving force
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class ZZBATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	
	

	// Set the throtttle between -1 and 1
	UFUNCTION (BlueprintCallable, Category = "Input")
		void SetThrottle(float throttle);
	
	//This is max force per track
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000; // assuming tank is 40T, and 1g acceleration
	
private:
	UTankTrack();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


};

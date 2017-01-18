// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"  // must be the last include

/**
 * 
 */
UCLASS(Blueprintable)
class ZZBATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TankPlayerController")
	float CrossHairXLocation = 0.5f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TankPlayerController")
	float CrossHaireYLocation = 0.33333333f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TankPlayerController")
		float LineTraceRange =1000000.0f;


private:

	// Called every frame
	virtual void PlayerTick(float deltaSeconds) override;

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	void AimTowardCrosshair();

	bool GetSightHiRaytLocation(FVector& hitLocation) const;

	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;

	bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;

	
};

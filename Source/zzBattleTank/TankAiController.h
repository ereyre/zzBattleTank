// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Tank.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class ZZBATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;


	void BeginPlay() override;
	
	virtual void Tick(float DeltaTime);

};

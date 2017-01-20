// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAiController.generated.h"


class ATank;

/**
 *  Tanp Cpp AI Controller
 */
UCLASS()
class ZZBATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	

	void BeginPlay() override;
	
	virtual void Tick(float DeltaTime);

};

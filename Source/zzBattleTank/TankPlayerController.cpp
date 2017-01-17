// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* tank = GetControlledTank();

	if (!tank) {
		UE_LOG(LogTemp, Error, TEXT(" Error while geting possesed tank")) 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play %s "), *tank->GetName());
	}

	

	


}
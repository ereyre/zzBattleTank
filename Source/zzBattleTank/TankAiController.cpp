// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankAiController.h"

ATank * ATankAiController::GetPlayerTank() const
{
	ATank* tank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	return tank;
}

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	ATank* tank = GetPlayerTank();

	if (!tank) {
		UE_LOG(LogTemp, Error, TEXT(" AI Say : I dont find a player tankj"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Say : Found the tank of : %s "), *tank->GetName());
	}
}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

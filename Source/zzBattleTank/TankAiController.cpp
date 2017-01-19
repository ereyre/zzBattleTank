// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "Tank.h"
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
		UE_LOG(LogTemp, Error, TEXT(" AI Say : I dont find any player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Say : Found the my tank of : %s "), *tank->GetName());
	}
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find the player tank
	ATank* playerTank = GetPlayerTank();

	// aim at it (if exist)
	if (playerTank) {

		// TODO move toward the player

		// Aim toward th eplayer
		GetControlledTank()->AimAt(playerTank->GetActorLocation());


		// TODO shoot to player tank if in range

	}


}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "Tank.h"
#include "TankAiController.h"



void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	ATank* tank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!tank) {
		UE_LOG(LogTemp, Error, TEXT(" AI Say : I dont find any player tank"))
	}
	
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find the player tank
	ATank* playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* myAiTank = Cast<ATank>(GetPawn());

	// aim at it (if exist)
	if (playerTank) {

		// TODO move toward the player
		MoveToActor(playerTank, AcceptanceRadius); //TODO check if radius is in centimenter
		// Aim toward th eplayer
		myAiTank->AimAt(playerTank->GetActorLocation());


		// Fire if ready
		myAiTank->Fire();

	}
}



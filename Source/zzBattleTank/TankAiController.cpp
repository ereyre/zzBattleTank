// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankAiController.h"



void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find the player tank  
	// TODO Convert from Tank to Pawn
	ATank* playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* myAiTank = Cast<ATank>(GetPawn());

	// aim at it (if exist)
	if (playerTank) {

		//get my aiming component to be able to aim and fire
		UTankAimingComponent* tankAimingComp = myAiTank->FindComponentByClass<UTankAimingComponent>();
		if (!ensure(tankAimingComp)) { return;  }

		// TODO move toward the player
		MoveToActor(playerTank, AcceptanceRadius); //TODO check if radius is in centimenter
		// Aim toward th eplayer
		tankAimingComp->AimAt(playerTank->GetActorLocation());


		// Fire if ready
		tankAimingComp->Fire();

	}
}



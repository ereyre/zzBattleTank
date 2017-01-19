// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "Tank.h"
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

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank())
		return;   //do nothing


	FVector hitLocation; // Out parameter
	
	if (GetSightHiRaytLocation(hitLocation)) {
		// if we hits the landscape
		// tell controlled tank to aim at this point

		GetControlledTank()->AimAt(hitLocation);
	}

	
}

bool ATankPlayerController::GetSightHiRaytLocation(FVector& hitLocation) const
{
	// Find the crosshaire position
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(viewportSizeX*CrossHairXLocation, viewportSizeY*CrossHaireYLocation);

	FVector lookDirection;

	if (GetLookDirection(screenLocation, lookDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT(" Look direction : %s"), *lookDirection.ToString());
		// Linetrace along  that look direction and see what we hit (up to may range)

		GetLookVectorHitLocation(lookDirection, hitLocation);
	}


	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const
{
	// "de-repoject" the screen position of the crosshair to world direction
	FVector  worldLocation;


	if (!DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, lookDirection)) {
		UE_LOG(LogTemp, Error, TEXT("Can't deproject scrfeen to world !!!!"));
		return false;
	}

	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector & hitLocation) const
{
	
	FVector startLocation = PlayerCameraManager->GetCameraLocation();
	FVector endLocation = startLocation + (lookDirection * LineTraceRange);

	// Draw a red trace in the world to visualise
	//DrawDebugLine(GetWorld(), startLocation, endLocation, FColor(255, 0, 0), false, -1.0f, 0.0f, 10.0f);

		
	FHitResult hitResult;

	if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility)) {
		// We hit something  !!!!

		// for memory 
		//AActor* actorHit = hitResult.GetActor();
		//hitLocation = actorHit->GetTransform().GetLocation();
		//on va lui demander son petiot nom
		//UE_LOG(LogTemp, Warning, TEXT("We Hit something at  which name is %s "), *actorHit->GetName());


		hitLocation = hitResult.Location;
		return true;
	}

	

	hitLocation = FVector(0);
	return false;
}




// Tick


void ATankPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f : PLayer controller Tick "), time);

	AimTowardCrosshair();
}
	





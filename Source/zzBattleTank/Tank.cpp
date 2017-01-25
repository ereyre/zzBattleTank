// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);

}





void ATank::Fire()
{
	
	// protects
	if (!ensure(Barrel))
		return;

	if (!ensure(ProjectileBlueprint)) {
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Error, TEXT("%f : Tank fire Error : No projectile defined"), time);
		return;
	}

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;

	if (isReloaded) {
		// Spawn a projectile 

		FVector  startLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator startRotation = Barrel->GetSocketRotation(FName("Projectile"));

		/*
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f : Tank fire at from  %s"), time, *startLocation.ToString());
		*/

		auto projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			startLocation,
			startRotation);

		float dummyLaunchSpeed = 0.0f; // TODO remove once wired
		projectile->LaunchProjectile(dummyLaunchSpeed); // TODO : correct when refactored


		//reset timmer for fire
		LastFireTime = FPlatformTime::Seconds();
	}




}


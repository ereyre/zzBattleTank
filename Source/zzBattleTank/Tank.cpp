// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning, TEXT("MMM : DAns le constructeur du tank"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("MMM : DAns le Begin play du tank"));
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);

}

void ATank::AimAt(FVector hitLocation)
{
	if (!TankAimingComponent) {
		UE_LOG(LogTemp, Error, TEXT(" PAs de aiming component dans le char !!!!"));
		return;
	}
	
	TankAimingComponent->AimAt(hitLocation, LaunchSpeed);

	
}




void ATank::Fire()
{
	
	// protects
	if (!Barrel)
		return;

	if (!ProjectileBlueprint) {
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

		projectile->LaunchProjectile(LaunchSpeed);


		//reset timmer for fire
		LastFireTime = FPlatformTime::Seconds();
	}




}


// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// initialisation of the default for the fireingstatus
	FiringStatus = EFiringStatus::Reloading;

	AimDirection = FVector(0.0f);

}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// So first fire is dalayed for the first reload
	LastFireTime = FPlatformTime::Seconds();
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTime) {
		FiringStatus = EFiringStatus::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringStatus = EFiringStatus::Aiming;
	}
	else {
		FiringStatus = EFiringStatus::Locked;
	}
}

void UTankAimingComponent::AimAt(FVector hitLocation)
{
	// just a little check
	if (!Barrel)
		return;

	FVector outLaunchVelocity;
	FVector startLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		outLaunchVelocity,
		startLocation,
		hitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace // Paramater must be present to prevent bug
	);

	if (bHaveAimSolution) {
		AimDirection = outLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards();


	}
	/*else {
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f : No valid shoot solution for %s"), time, *GetOwner()->GetName())
	}
	*/
	//DrawDebugLine(GetWorld(), startLocation, hitLocation, FColor(255, 0, 0), false, -1.0f, 0.0f, 10.0f);


}

void UTankAimingComponent::Initialise(UTankBarrel * barrelToSet, UTankTurret * turretToSet)
{
	Barrel = barrelToSet;
	Turret = turretToSet;
}


void UTankAimingComponent::MoveBarrelTowards()
{

	if (!Barrel || !Turret) {
		UE_LOG(LogTemp, Warning, TEXT("Move Barel fail because of missing Barrel or Turret"));
		return;
	}

	// Workout difference between current barel rotation and aimDirection

	auto barrelRotation = Barrel->GetForwardVector().Rotation();
	auto aimAsRotator = AimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotation;


	Barrel->Elevate(deltaRotator.Pitch); 
	Turret->Rotate(deltaRotator.Yaw);  

}

void UTankAimingComponent::Fire()
{
	// protects
	if (!ensure(Barrel))
		return;

	if (!ensure(ProjectileBlueprint)) {
		UE_LOG(LogTemp, Error, TEXT("Tank fire Error : No projectile defined"));
		return;
	}

	

	if (FiringStatus != EFiringStatus::Reloading) {
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

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }

	auto barrelForward = Barrel->GetForwardVector();



	return !barrelForward.Equals(AimDirection, 0.01f); 
}

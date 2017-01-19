// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimAt(FVector hitLocation, float launchSpeed)
{
	// just a little check
	if (!Barrel)
		return;

	FVector outLaunchVelocity;
	FVector startLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity

	if (UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, startLocation, hitLocation, launchSpeed)) {
		FVector aimDirection = outLaunchVelocity.GetSafeNormal();

		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *GetOwner()->GetName(),*aimDirection.ToString())
	}
	/*else {
		UE_LOG(LogTemp, Warning, TEXT("No valid shoot solution for %s"), *GetOwner()->GetName())
	}*/

	

	//DrawDebugLine(GetWorld(), startLocation, hitLocation, FColor(255, 0, 0), false, -1.0f, 0.0f, 10.0f);


}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * barrelToSet)
{
	Barrel = barrelToSet;
}


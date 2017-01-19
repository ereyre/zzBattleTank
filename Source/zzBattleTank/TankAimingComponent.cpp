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
	FString tankName = GetOwner()->GetName();
	FVector barrelLocation = Barrel->GetComponentLocation();

	UE_LOG(LogTemp, Warning, TEXT("Tank %s aim at : %s from %s at lauch speed %f"), *tankName, *hitLocation.ToString(), *barrelLocation.ToString(), *(&launchSpeed));

	//draw lines to visualize that
	//DrawDebugLine(GetWorld(), barrelLocation, hitLocation, FColor(255, 0, 0), false, -1.0f, 0.0f, 10.0f);
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * barrelToSet)
{
	Barrel = barrelToSet;
}


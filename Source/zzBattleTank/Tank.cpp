// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector hitLocation)
{
	FString tankName = GetName();

	UE_LOG(LogTemp, Warning, TEXT("Tank %s aim at : %s"), *tankName,  *hitLocation.ToString());

	//draw lines to visualize that
	//DrawDebugLine(GetWorld(), GetTransform().GetLocation(), hitLocation, FColor(255, 0, 0), false, -1.0f, 0.0f, 10.0f);



}


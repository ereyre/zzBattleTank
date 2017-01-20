// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Instantiation du component de movement
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));

	// set it's default
	ProjectileComponent->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LaunchProjectile(float speed)
{
	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f : Projectil launched at %f"), time, speed);


	ProjectileComponent->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	ProjectileComponent->Activate();


}


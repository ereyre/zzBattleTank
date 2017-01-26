// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming crosshair color
UENUM()
enum class EFiringStatus : uint8
{
	Unknow,
	Reloading,
	Locked,
	Aiming
};


//Forward declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;


// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZZBATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Aiming status
	UPROPERTY(BlueprintReadOnly, Category = "Status")
		EFiringStatus FiringStatus = EFiringStatus::Unknow;

	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// to aim at a direction
	void AimAt(FVector hitLocation);

	// IKnitialise movement Compoenent and add tracks
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* barrelToSet, UTankTurret* turretToSet);

	UPROPERTY(EditDEfaultsOnly, Category = "Firing")
		float LaunchSpeed = 10000;   //sensible starting value of 1000 m/s

	void MoveBarrelTowards();

	// Fire the main gun
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();



	UPROPERTY(EditDEfaultsOnly, Category = "Firing")
		float ReloadTime = 3.0;


	UPROPERTY(EditDEfaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint; // le pourquoi : https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/







private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	double LastFireTime = 0;

	bool IsBarrelMoving();

	FVector AimDirection; 

	
};

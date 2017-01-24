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
	void AimAt(FVector hitLocation,float launchSpeed);

	void SetBarrelReference(UTankBarrel* barrelToSet);

	void SetTurretReference(UTankTurret* turretToSet);

	void MoveBarrelTowards(FVector aimDirection);

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	


	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//Forward declaration
class UTankBarrel; 
class UTankAimingComponent;
class UTankTurret; 

// Tank Cpp based on Pawn
UCLASS()
class ZZBATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:
	
	void AimAt(FVector hitLocation); 

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* turretToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;   //sensible starting value of 1000 m/s
 
	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	
};

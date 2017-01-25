// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//Forward declaration
class UTankBarrel; 
class UTankTurret; 
class AProjectile;


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

	// local reference for spawning projectile
	UTankBarrel* Barrel = nullptr;   //TODO remove


	

	double LastFireTime = 0;

public:
	


	UPROPERTY(EditDEfaultsOnly, Category = "Firing")
		float ReloadTime = 3.0;


	UPROPERTY(EditDEfaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint; // le pourquoi : https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/

	
	
 
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

	void AimAt(FVector hitLocation);
	

	
};

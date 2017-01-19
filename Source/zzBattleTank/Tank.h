// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

UCLASS()
class ZZBATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:
	
	void AimAt(FVector hitLocation); 

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* barrelToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;   //sensible starting value of 1000 m/s
 


protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	
};

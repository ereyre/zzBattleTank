// Fill out your copyright notice in the Description page of Project Settings.

#include "zzBattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float relativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT(" Elevate called at speed %f "), *(&relativeSpeed));
}
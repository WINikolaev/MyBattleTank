// Fill out your copyright notice in the Description page of Project Settings.



#include "TankBarrel.h"
#include "MyBattleTank.h"



void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() callsed: %f"), DegreesPerSecond)

}
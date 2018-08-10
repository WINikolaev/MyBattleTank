// Fill out your copyright notice in the Description page of Project Settings.



#include "TankBarrel.h"
#include "MyBattleTank.h"



void UTankBarrel::Elevate(float RelativeSpeed)
{
	// будем поход вращать башню
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MimElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
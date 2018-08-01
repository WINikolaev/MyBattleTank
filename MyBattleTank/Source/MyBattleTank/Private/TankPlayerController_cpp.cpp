// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_cpp.h"

void ATankPlayerController_cpp::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController  possesing %s"), *(ControlledTank->GetName()))
	}

}


void ATankPlayerController_cpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	

}

ATank * ATankPlayerController_cpp::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_cpp::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if(GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		/// Get World location through cosshair
		/// if it hits landscape
		/// tell controlled tank to aim this point
		//UE_LOG(LogTemp, Warning, TEXT("AimTowardsCrosshair"))
	}
	

}

bool ATankPlayerController_cpp::GetSightRayHitLocation(FVector & HitLocation) const
{

	/// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	/// De-project the screen psotion of the crosshair to a world direction
	/// Lin-trace along tha look direction, and see what we hit(up to max range)

	return false;
}

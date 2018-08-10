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

	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f AimTowardsCrosshair called"), Time)

	FVector HitLocation;
	if(GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	

}

bool ATankPlayerController_cpp::GetSightRayHitLocation(FVector & HitLocation) const
{

	/// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		this->GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	/// Lin-trace along tha look direction, and see what we hit(up to max range)

	return true;
}


/// линия трасировки
bool ATankPlayerController_cpp::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
	  )
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}


bool ATankPlayerController_cpp::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	/// De-project the screen psotion of the crosshair to a world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
								   ScreenLocation.Y,
								   CameraWorldLocation,
								   LookDirection);
}
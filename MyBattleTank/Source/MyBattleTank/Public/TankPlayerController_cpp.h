// Copyright EmbraceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_cpp.generated.h"


/**
*  REesponsible for helping the player
*/
UCLASS()
class ATankPlayerController_cpp : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

public:
	

	void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();

	/// Return an OUT parameter< true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 10000000;
;};


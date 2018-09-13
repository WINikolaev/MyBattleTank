// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ConttrolledTank = GetPawn();
	if (!ensure(PlayerTank) && ConttrolledTank) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check readius is in cm
	auto AimingComponent = ConttrolledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	// TODO Fix firinig
	//ConttrolledTank->Fire(); /// TODO limit firing rate
	
}







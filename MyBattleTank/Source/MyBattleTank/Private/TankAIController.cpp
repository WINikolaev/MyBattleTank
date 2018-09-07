// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ConttrolledTank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check readius is in cm

		ConttrolledTank->AimAt(PlayerTank->GetActorLocation());
		///
		ConttrolledTank->Fire(); /// TODO limit firing rate
	}
}







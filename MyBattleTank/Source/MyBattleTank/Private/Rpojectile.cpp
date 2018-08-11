// Fill out your copyright notice in the Description page of Project Settings.

#include "Rpojectile.h"


// Sets default values
ARpojectile::ARpojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARpojectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARpojectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


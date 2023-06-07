// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorTile.h"

AFloorTile::AFloorTile()
{
	// Disable calling Tick()
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(
		TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
}

void AFloorTile::BeginPlay()
{
	Super::BeginPlay();
}

// Disabled
void AFloorTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


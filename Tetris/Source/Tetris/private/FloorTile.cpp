// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorTile.h"

// Sets default values
AFloorTile::AFloorTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(
		TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

	PrimaryMaterial = nullptr;
	SecondaryMaterial = nullptr;
	ExtraMaterial = nullptr;
}

// Called when the game starts or when spawned
void AFloorTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Disabled
void AFloorTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


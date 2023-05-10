// Fill out your copyright notice in the Description page of Project Settings.


#include "GameField.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGameField::AGameField()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("StaticMeshComponent"));
    RootComponent = StaticMeshComponent;

    PrimaryMaterial = nullptr;

}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector Location1(0, 0, 150);
    FVector Location2(100, 100, 150);

    DrawDebugPoint(GetWorld(), Location1, 50, FColor(0, 200, 200), true);

    FVector Z(0, 0, 100);
    DrawDebugCylinder(GetWorld(), FVector(40, 40, 100), FVector(40, 40, 400), 10, 10, FColor::Blue, true);
    DrawDebugDirectionalArrow(GetWorld(), Location1, Location1 + Z, 50, FColor::Red, true);
    DrawDebugDirectionalArrow(GetWorld(), Location2, Location2 + Z, 50, FColor::Green, true);
}

// Called to bind functionality to input
void AGameField::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::SetupPlayerInputComponent()"));

}


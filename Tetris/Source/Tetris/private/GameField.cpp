// Fill out your copyright notice in the Description page of Project Settings.


#include "GameField.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGameField::AGameField()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("StaticMeshComponent"));
    RootComponent = StaticMeshComponent;

    PrimaryMaterial = nullptr;

}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
    Super::BeginPlay();

    DbgDraw();
}

// Called every frame
void AGameField::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGameField::DbgDraw()
{
    auto world = GetWorld();

    FVector Location1(0.1, 0.1, 100);
    FVector Location2(0.5, 0.5, 100);
    FVector Location3(0.1, 100, 100);
    FVector Z(0, 0, 100);

    //DrawDebugPoint(world, Location1, 50, FColor(0, 200, 200), true);

    FVector center(2000 / 2, 1000 / 2, 100);
    DrawDebugCylinder(world, center, center + FVector(0, 0, 400), 10, 100, FColor::Blue, true, -1, 0, 2);

    //DrawDebugDirectionalArrow(world,
    //    Location1, Location1 + Z, 50, FColor::Red, true, -1, 0, 2);
    //DrawDebugDirectionalArrow(world,
    //    Location2, Location2 + Z, 50, FColor::Green, true, -1, 0, 2);

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            FVector From(j * 100, i * 100, 100);
            FVector To = From + Z;

            DrawDebugDirectionalArrow(world,
                From, To, 50, FColor::Blue, true, -1, 0, 2);

            FString t = FString::FromInt(j) + "," + FString::FromInt(i);
            // Max 128 DrawDebugString but can be modified
            if (i % 2 == 0 && j % 2 == 0)
            {
                DrawDebugString(world, To, t, 0, FColor::Yellow, -1, false, 1.0f);
            }
        }
    }
}

// Called to bind functionality to input
void AGameField::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::SetupPlayerInputComponent()"));

}


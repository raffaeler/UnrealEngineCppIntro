// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemZ.h"

void AItemZ::BeginPlay()
{
    Super::BeginPlay();

    ShiftChildrenActors(FVector(-100, -200, 0));
}

FMatrix44f AItemZ::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Za;
    case 1:
        return Zb;
    case 2:
        return Zc;
    case 3:
        return Zd;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemZ::GetShape - Bad rotation: %d"), Rotation);
        return Za;
    }
}

EShapeKind AItemZ::GetShapeKind()
{
    return EShapeKind::Z;
}

bool AItemZ::GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator)
{
    if (Location == nullptr || Rotator == nullptr) return false;
    switch (Rotation)
    {
    case 0:
        *Location = LocationA;
        *Rotator = RotatorA;
        break;
    case 1:
        *Location = LocationB;
        *Rotator = RotatorB;
        break;
    case 2:
        *Location = LocationC;
        *Rotator = RotatorC;
        break;
    case 3:
        *Location = LocationD;
        *Rotator = RotatorD;
        break;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemZ::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemZ::TetrisRotate(int Rotation)
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> ItemZ::TetrisRotate rotation: %d"), Rotation);
    switch (Rotation)
    {
    case 0:
        //ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorA);
        break;
    case 1:
        //ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorB);
        break;
    case 2:
        //ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorC);
        break;
    case 3:
        //ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorD);
        break;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemZ::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}
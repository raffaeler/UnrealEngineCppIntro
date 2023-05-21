// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemO.h"

void AItemO::BeginPlay()
{
    Super::BeginPlay();

    ShiftChildrenActors(FVector(-50, -50, 0));
}

FMatrix44f AItemO::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Oa;
    case 1:
        return Ob;
    case 2:
        return Oc;
    case 3:
        return Od;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::GetShape - Bad rotation: %d"), Rotation);
        return Oa;
    }
}

EShapeKind AItemO::GetShapeKind()
{
    return EShapeKind::O;
}

bool AItemO::GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemO::TetrisRotate(int Rotation)
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::TetrisRotate rotation: %d"), Rotation);
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemT.h"

void AItemT::BeginPlay()
{
    Super::BeginPlay();

    ShiftChildrenActors(FVector(-100, -100, 0));
}

FMatrix44f AItemT::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Ta;
    case 1:
        return Tb;
    case 2:
        return Tc;
    case 3:
        return Td;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemT::GetShape - Bad rotation: %d"), Rotation);
        return Ta;
    }
}

EShapeKind AItemT::GetShapeKind()
{
    return EShapeKind::T;
}

bool AItemT::GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemT::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemT::TetrisRotate(int Rotation)
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> ItemT::TetrisRotate rotation: %d"), Rotation);
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemT::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}

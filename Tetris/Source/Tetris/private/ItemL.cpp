// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemL.h"

FMatrix44f AItemL::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return La;
    case 1:
        return Lb;
    case 2:
        return Lc;
    case 3:
        return Ld;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemL::GetShape - Bad rotation: %d"), Rotation);
        return La;
    }
}

EShapeKind AItemL::GetShapeKind()
{
    return EShapeKind::L;
}

bool AItemL::GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemL::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

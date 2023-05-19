// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemS.h"

FMatrix44f AItemS::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Sa;
    case 1:
        return Sb;
    case 2:
        return Sc;
    case 3:
        return Sd;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemS::GetShape - Bad rotation: %d"), Rotation);
        return Sa;
    }
}

EShapeKind AItemS::GetShapeKind()
{
    return EShapeKind::S;
}

bool AItemS::GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemS::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

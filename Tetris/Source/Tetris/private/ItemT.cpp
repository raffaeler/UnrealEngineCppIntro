// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemT.h"

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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemT::GetShape - Bad rotation"));
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemT::GetLocationAndRotatorbyRotation - Bad rotation"));
        return false;
    }

    return true;
}

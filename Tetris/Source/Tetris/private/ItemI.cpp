// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemI.h"

FMatrix44f AItemI::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Ia;
    case 1:
        return Ib;
    case 2:
        return Ic;
    case 3:
        return Id;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemI::GetShape - Bad rotation"));
        return Ia;
    }
}

bool AItemI::GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemI::GetLocationAndRotatorbyRotation - Bad rotation"));
        return false;
    }

    return true;
}

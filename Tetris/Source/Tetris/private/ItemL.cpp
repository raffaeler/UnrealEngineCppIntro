// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemL.h"

void AItemL::BeginPlay()
{
    Super::BeginPlay();

}

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

bool AItemL::GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset)
{
    if (PreOffset == nullptr || Rotator == nullptr) return false;
    switch (Rotation)
    {
    case 0:
        *PreOffset= PreOffsetA;
        *Rotator = RotatorA;
        *PostOffset = PostOffsetA;
        break;
    case 1:
        *PreOffset= PreOffsetB;
        *Rotator = RotatorB;
        *PostOffset = PostOffsetB;
        break;
    case 2:
        *PreOffset= PreOffsetC;
        *Rotator = RotatorC;
        *PostOffset = PostOffsetC;
        break;
    case 3:
        *PreOffset= PreOffsetD;
        *Rotator = RotatorD;
        *PostOffset = PostOffsetD;
        break;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemL::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}


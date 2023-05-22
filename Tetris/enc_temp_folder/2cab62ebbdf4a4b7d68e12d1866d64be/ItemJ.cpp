// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemJ.h"

void AItemJ::BeginPlay()
{
    Super::BeginPlay();

}

FMatrix44f AItemJ::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Ja;
    case 1:
        return Jb;
    case 2:
        return Jc;
    case 3:
        return Jd;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::GetShape - Bad rotation: %d"), Rotation);
        return Ja;
    }
}

EShapeKind AItemJ::GetShapeKind()
{
    return EShapeKind::J;
}

bool AItemJ::GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemJ::TetrisRotate(int Rotation)
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::TetrisRotate rotation: %d"), Rotation);
    switch (Rotation)
    {
    case 0:
        ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorA);
        break;
    case 1:
        ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorB);
        break;
    case 2:
        ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorC);
        break;
    case 3:
        ShiftChildrenActors(FVector(-100, -200, 0));
        SetActorRotation(RotatorD);
        break;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}
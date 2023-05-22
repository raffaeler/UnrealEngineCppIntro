// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemS.h"

void AItemS::BeginPlay()
{
    Super::BeginPlay();

    //ShiftChildrenActors(FVector(-100, -200, 0));
}

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

bool AItemS::GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemS::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemS::TetrisRotate(int Rotation)
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> ItemS::TetrisRotate rotation: %d"), Rotation);
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemS::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}

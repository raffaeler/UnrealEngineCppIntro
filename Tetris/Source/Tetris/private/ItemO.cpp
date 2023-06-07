// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemO.h"

void AItemO::BeginPlay()
{
    Super::BeginPlay();

    //ShiftChildrenActors(FVector(-50, -50, 0));
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

bool AItemO::GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemO::TetrisRotate(int Rotation)
{
    //UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::TetrisRotate rotation: %d"), Rotation);
    switch (Rotation)
    {
    case 0:
        SetActorRotation(RotatorA);
        break;
    case 1:
        SetActorRotation(RotatorB);
        break;
    case 2:
        SetActorRotation(RotatorC);
        break;
    case 3:
        SetActorRotation(RotatorD);
        break;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}

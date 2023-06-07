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

bool AItemJ::GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemJ::TetrisRotate(int Rotation)
{
    //UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::TetrisRotate rotation: %d"), Rotation);
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}

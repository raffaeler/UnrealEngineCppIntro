// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemI.h"

void AItemI::BeginPlay()
{
    Super::BeginPlay();

    //ShiftChildrenActors(FVector(-300, -200, 0));
}

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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemI::GetShape - Bad rotation: %d"), Rotation);
        return Ia;
    }
}

EShapeKind AItemI::GetShapeKind()
{
    return EShapeKind::I;
}

bool AItemI::GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset)
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemI::GetLocationAndRotatorbyRotation - Bad rotation: %d"), Rotation);
        return false;
    }

    return true;
}

void AItemI::TetrisRotate(int Rotation)
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> ItemI::TetrisRotate rotation: %d"), Rotation);
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
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemI::GetShape - Bad rotation: %d"), Rotation);
        return;
    }
}

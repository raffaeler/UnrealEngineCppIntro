// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemI.generated.h"

/**
 *
 */
UCLASS()
class TETRIS_API AItemI : public AItemBase
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

private:
    FMatrix44f Ia = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 1, 1),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));

        FVector PreOffsetA = FVector(0, 0, 0);
        FRotator RotatorA = FRotator(0, 0, 0);
        FVector PostOffsetA = FVector(0, 0, 0);

    FMatrix44f Ib = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));
        FVector PreOffsetB = FVector(0, 0, 0);
        FRotator RotatorB = FRotator(0, -90, 0);
        FVector PostOffsetB = FVector(0, 0, 0);

    FMatrix44f Ic = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 1, 1),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));
        FVector PreOffsetC = FVector(0, 0, 0);
        FRotator RotatorC = FRotator(0, -180, 0);
        FVector PostOffsetC = FVector(0, 0, 0);

    FMatrix44f Id = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));
        FVector PreOffsetD = FVector(0, 0, 0);
        FRotator RotatorD = FRotator(0, 90, 0);
        FVector PostOffsetD = FVector(0, 0, 0);



public:
    FMatrix44f GetShape(int Rotation) override;
    EShapeKind GetShapeKind() override;
    bool GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset) override;
    void TetrisRotate(int Rotation) override;

};

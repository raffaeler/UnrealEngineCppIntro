// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemS.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API AItemS : public AItemBase
{
	GENERATED_BODY()

public:
    virtual void BeginPlay() override;

private:

    FMatrix44f Sa = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector PreOffsetA = FVector(0, 0, 0);
    FRotator RotatorA = FRotator(0, 0, 0);
    FVector PostOffsetA = FVector(0, 100, 0);

    FMatrix44f Sb = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 0, 0));
    FVector PreOffsetB = FVector(0, 0, 0);
    FRotator RotatorB = FRotator(0, -90, 0);
    FVector PostOffsetB = FVector(100, 300, 0);

    FMatrix44f Sc = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector PreOffsetC = FVector(0, 0, 0);
    FRotator RotatorC = FRotator(0, -180, 0);
    FVector PostOffsetC = FVector(300, 300, 0);

    FMatrix44f Sd = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 0, 0));
    FVector PreOffsetD = FVector(0, 0, 0);
    FRotator RotatorD = FRotator(0, 90, 0);
    FVector PostOffsetD = FVector(300, 0, 0);


public:
	FMatrix44f GetShape(int Rotation) override;
    EShapeKind GetShapeKind() override;
    bool GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset) override;
    void TetrisRotate(int Rotation) override;

};

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

    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FVector LocationA = FVector(0, 0, 0);
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FRotator RotatorA = FRotator(0, 0, 0);

    FMatrix44f Ib = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FVector LocationB = FVector(0, 0, 0);
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FRotator RotatorB = FRotator(0, -90, 0);

    FMatrix44f Ic = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 1, 1),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FVector LocationC = FVector(0, 0, 0);
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FRotator RotatorC = FRotator(0, -180, 0);

    FMatrix44f Id = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FVector LocationD = FVector(0, 0, 0);
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisRotation")
        FRotator RotatorD = FRotator(0, 90, 0);



public:
    FMatrix44f GetShape(int Rotation) override;
    EShapeKind GetShapeKind() override;
    bool GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator) override;
    void TetrisRotate(int Rotation) override;

};

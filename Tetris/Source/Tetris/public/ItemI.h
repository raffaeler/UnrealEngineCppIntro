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
	
private:
    FMatrix44f Ia = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 1, 1),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector LocationA = FVector(-300, 0, 0);
    FRotator RotatorA = FRotator(0, 0, 0);

    FMatrix44f Ib = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));
    FVector LocationB = FVector(100, 300, 0);
    FRotator RotatorB = FRotator(0, -90, 0);

    FMatrix44f Ic = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 1, 1),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector LocationC = FVector(200, -100, 0);
    FRotator RotatorC = FRotator(0, -180, 0);

    FMatrix44f Id = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));
    FVector LocationD = FVector(0, -200, 0);
    FRotator RotatorD = FRotator(0, 90, 0);



public:
	FMatrix44f GetShape(int Rotation) override;
    EShapeKind GetShapeKind() override;
    bool GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator) override;

};

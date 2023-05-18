// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemT.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API AItemT : public AItemBase
{
	GENERATED_BODY()
	
private:

    FMatrix44f Ta = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 1, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector LocationA = FVector(-200, 0, 0);
    FRotator RotatorA = FRotator(0, 0, 0);

    FMatrix44f Tb = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector LocationB = FVector(0, 200, 0);
    FRotator RotatorB = FRotator(0, -90, 0);

    FMatrix44f Tc = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(1, 1, 1, 0),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector LocationC = FVector(200, 0, 0);
    FRotator RotatorC = FRotator(0, -180, 0);

    FMatrix44f Td = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));
    FVector LocationD = FVector(0, -200, 0);
    FRotator RotatorD = FRotator(0, 90, 0);


public:
	FMatrix44f GetShape(int Rotation) override;
    bool GetLocationAndRotatorbyRotation(int Rotation, FVector* Location, FRotator* Rotator) override;


};

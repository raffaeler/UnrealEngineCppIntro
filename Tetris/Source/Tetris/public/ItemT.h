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

    FMatrix44f Tb = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Tc = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(1, 1, 1, 0),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Td = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));


public:
	FMatrix44f GetShape(int Rotation) override;

};

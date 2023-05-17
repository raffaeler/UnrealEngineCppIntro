// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemL.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API AItemL : public AItemBase
{
	GENERATED_BODY()

private:
    FMatrix44f La = FMatrix44f(
        FPlane4f(1, 1, 1, 0),
        FPlane4f(1, 0, 0, 0),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Lb = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Lc = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(1, 1, 1, 0),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Ld = FMatrix44f(
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));

public:
    FMatrix44f GetShape(int Rotation) override;
	
};

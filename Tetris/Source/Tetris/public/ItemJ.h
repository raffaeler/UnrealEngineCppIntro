// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemJ.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API AItemJ : public AItemBase
{
	GENERATED_BODY()

private:
    FMatrix44f Ja = FMatrix44f(
        FPlane4f(1, 1, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Jb = FMatrix44f(
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Jc = FMatrix44f(
        FPlane4f(1, 0, 0, 0),
        FPlane4f(1, 1, 1, 0),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Jd = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));


public:
	FMatrix44f GetShape(int Rotation) override;

};

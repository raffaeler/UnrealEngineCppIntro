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

    FMatrix44f Ib = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));

    FMatrix44f Ic = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 1, 1),
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Id = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 1, 0));



public:
	FMatrix44f GetShape(int Rotation) override;

};

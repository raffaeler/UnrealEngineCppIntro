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
	
private:

    FMatrix44f Sa = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Sb = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Sc = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Sd = FMatrix44f(
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 0, 0));


public:
	FMatrix44f GetShape(int Rotation) override;

};

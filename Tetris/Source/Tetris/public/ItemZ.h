// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemZ.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API AItemZ : public AItemBase
{
	GENERATED_BODY()
	
private:

    FMatrix44f Za = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Zb = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Zc = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(1, 1, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Zd = FMatrix44f(
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 0, 0),
        FPlane4f(0, 0, 0, 0));



public:
	FMatrix44f GetShape(int Rotation) override;

};

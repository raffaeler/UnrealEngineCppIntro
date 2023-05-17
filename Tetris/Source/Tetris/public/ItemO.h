// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemO.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API AItemO : public AItemBase
{
	GENERATED_BODY()
	
private:
    FMatrix44f Oa = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Ob = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Oc = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 0, 0));

    FMatrix44f Od = FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 0, 0));


public:
	FMatrix44f GetShape(int Rotation) override;

};

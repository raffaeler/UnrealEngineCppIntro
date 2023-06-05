// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TetrisPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API ATetrisPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ATetrisPlayerState();
	
private:
	int32 Points;

public:
	int32 GetPoints();

	void IncrementPoints(int32 points);

};

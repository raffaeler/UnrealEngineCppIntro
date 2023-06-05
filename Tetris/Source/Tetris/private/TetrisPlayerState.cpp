// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisPlayerState.h"

ATetrisPlayerState::ATetrisPlayerState()
{
    Points = 0;
}

int32 ATetrisPlayerState::GetPoints()
{
    return Points;
}

void ATetrisPlayerState::IncrementPoints(int32 points)
{
    Points += points;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemZ.h"

FMatrix44f AItemZ::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Za;
    case 1:
        return Zb;
    case 2:
        return Zc;
    case 3:
        return Zd;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemZ::GetShape - Bad rotation"));
        return Za;
    }
}
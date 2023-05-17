// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemL.h"

FMatrix44f AItemL::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return La;
    case 1:
        return Lb;
    case 2:
        return Lc;
    case 3:
        return Ld;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemL::GetShape - Bad rotation"));
        return La;
    }
}
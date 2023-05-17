// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemS.h"

FMatrix44f AItemS::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Sa;
    case 1:
        return Sb;
    case 2:
        return Sc;
    case 3:
        return Sd;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemS::GetShape - Bad rotation"));
        return Sa;
    }
}
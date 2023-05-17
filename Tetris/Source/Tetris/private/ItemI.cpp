// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemI.h"

FMatrix44f AItemI::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Ia;
    case 1:
        return Ib;
    case 2:
        return Ic;
    case 3:
        return Id;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemI::GetShape - Bad rotation"));
        return Ia;
    }
}
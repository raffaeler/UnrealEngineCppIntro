// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemT.h"

FMatrix44f AItemT::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Ta;
    case 1:
        return Tb;
    case 2:
        return Tc;
    case 3:
        return Td;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemT::GetShape - Bad rotation"));
        return Ta;
    }
}
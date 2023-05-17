// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemO.h"

FMatrix44f AItemO::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Oa;
    case 1:
        return Ob;
    case 2:
        return Oc;
    case 3:
        return Od;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemO::GetShape - Bad rotation"));
        return Oa;
    }
}
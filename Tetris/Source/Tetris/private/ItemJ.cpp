// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemJ.h"

FMatrix44f AItemJ::GetShape(int Rotation)
{
    switch (Rotation)
    {
    case 0:
        return Ja;
    case 1:
        return Jb;
    case 2:
        return Jc;
    case 3:
        return Jd;

    default:
        UE_LOG(LogTemp, Log, TEXT("Tetris> ItemJ::GetShape - Bad rotation"));
        return Ja;
    }
}
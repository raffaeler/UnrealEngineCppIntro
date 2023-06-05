// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisHUD.h"

ATetrisHUD::ATetrisHUD()
{
}

void ATetrisHUD::DrawHUD()
{
    // VS complains, but compiles :)
    Super::DrawHUD();
}

void ATetrisHUD::BeginPlay()
{
    Super::BeginPlay();

    if (TetrisWidgetClass)
    {
        TetrisWidget = CreateWidget<UTetrisWidget>(GetWorld(), TetrisWidgetClass);
        if (TetrisWidget)
        {
            TetrisWidget->AddToViewport();
        }
    }

    if (TetrisWidget)
    {
        TetrisWidget->UpdateScore(0);
    }
}

void ATetrisHUD::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ATetrisHUD::UpdateScore(int32 score)
{
    if (TetrisWidget)
    {
        TetrisWidget->UpdateScore(score);
    }
}
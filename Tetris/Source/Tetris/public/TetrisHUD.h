// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"

#include "TetrisWidget.h"

#include "TetrisHUD.generated.h"

/**
 *
 */
UCLASS()
class TETRIS_API ATetrisHUD : public AHUD
{
    GENERATED_BODY()

public:
    ATetrisHUD();

    virtual void DrawHUD() override;
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    UFUNCTION()
    void UpdateScore(int32 score);

    UPROPERTY(EditDefaultsOnly, Category = "Tetris HUD Widget")
    TSubclassOf<UTetrisWidget> TetrisWidgetClass;

private:
    UTetrisWidget* TetrisWidget = nullptr;
};

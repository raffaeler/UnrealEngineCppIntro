// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "EngineUtils.h"
#include "GameField.h"
#include "ItemBase.h"

#include "TetrisGameMode.generated.h"

/**
 *
 */
UCLASS()
class TETRIS_API ATetrisGameMode : public AGameMode
{
    GENERATED_BODY()

private:
    // Timer to start the game
    void SetupStartGameTimer();
    FTimerHandle StartGameTimer;
    FTimerDelegate StartGameDelegate;
    UFUNCTION() void OnStartGameTimer();
    void PreStartGame(int32 count, int32 maxCount);
    void StartGame();
    TArray<float> StartGameIntervals;
    int32 IntervalIndex = 0;

private:
    // Timer dropping items in the game field
    void SetupItemDropTimer(float Interval, bool bLoop, bool bStartNow);
    FTimerHandle ItemDropTimer;
    FTimerDelegate ItemDropDelegate;
    UFUNCTION() void OnItemDropTimer();
    uint32 ItemDropInterval = 0;


public:
    virtual void BeginPlay() override;

    // TSubclassOf is a template class that provides UClass type safety.
    UPROPERTY(EditDefaultsOnly, Category = "TetrisCore")
    TSubclassOf<AGameField> GameFieldClass;

    UPROPERTY(EditDefaultsOnly, Category = "TetrisCore")
    TMap<FString, TSubclassOf<AItemBase>> ItemClasses;

    // reference to a GameField object
    UPROPERTY(Transient)
    AGameField* GameField = nullptr;

    UPROPERTY(Transient)
    AItemBase* CurrentItem = nullptr;

    UPROPERTY()
    TArray<AActor*> DetachedActors;

public:
};

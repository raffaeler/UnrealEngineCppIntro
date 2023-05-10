// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameField.h"

#include "TetrisGameMode.generated.h"

/**
 *
 */
UCLASS()
class TETRIS_API ATetrisGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    // TSubclassOf is a template class that provides UClass type safety.
    UPROPERTY(EditDefaultsOnly, Category="TetrisCore")
    TSubclassOf<AGameField> GameFieldClass;

    // reference to a GameField object
    UPROPERTY(Transient)
        AGameField* GameField = nullptr;
};

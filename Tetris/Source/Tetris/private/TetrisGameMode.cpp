// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisGameMode.h"

void ATetrisGameMode::BeginPlay() {
    Super::BeginPlay();
    UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisGameMode::BeginPlay()"));

    if (GameFieldClass == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("GameFieldClass must be set in the BluePrint"));
        return;
    }

    FVector GameFieldPos(200, 200, 200);
    GameField = Cast<AGameField>(GetWorld()->SpawnActor(GameFieldClass, &GameFieldPos));
}

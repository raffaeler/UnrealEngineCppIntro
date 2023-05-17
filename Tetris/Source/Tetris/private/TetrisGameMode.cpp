// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisGameMode.h"

void ATetrisGameMode::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisGameMode::BeginPlay()"));

    if (GameFieldClass == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("GameFieldClass must be set in the BluePrint"));
        return;
    }

    auto world = GetWorld();
    //world->OriginLocation = FIntVector(730, 500, 100);
    
    //FVector GameFieldPos(0, 0, 0);
    FVector GameFieldPos(730, 500, 100);
    //GameField = Cast<AGameField>(world->SpawnActor(GameFieldClass, &GameFieldPos));
    //GameField = Cast<AGameField>(DefaultPawnClass.GetDefaultObject());
    GameField = Cast<AGameField>(*TActorIterator<AGameField>(GetWorld()));
    GameField->SetActorLocation(GameFieldPos);
    GameField->SetActorRotation(FRotator());

    //DrawDebugDirectionalArrow(world,
    //    FVector(0, 0, 100), FVector(0, 0, 600), 50, FColor::Orange, true, -1, 0, 10);


    ItemDropDelegate.BindUFunction(this, "OnItemDropTimer");

    StartGameDelegate.BindUFunction(this, "OnStartGameTimer");
    IntervalIndex = 0;
    StartGameIntervals.Push(1);
    //StartGameIntervals.Push(0.9);
    //StartGameIntervals.Push(0.9);
    SetupStartGameTimer();

}

void ATetrisGameMode::SetupStartGameTimer()
{
    UE_LOG(LogTemp, Display, TEXT("ATetrisGameMode::SetupStartGameTimer()"));

    auto world = GetWorld();
    float interval = StartGameIntervals[IntervalIndex];
    world->GetTimerManager().SetTimer(StartGameTimer, StartGameDelegate,
        interval, false);
}

void ATetrisGameMode::OnStartGameTimer()
{
    PreStartGame(IntervalIndex, StartGameIntervals.Num());

    if (++IntervalIndex < StartGameIntervals.Num())
    {
        // TODO: Show graphics with counter
        UE_LOG(LogTemp, Display, TEXT("StartGame %d"), StartGameIntervals.Num() - (IntervalIndex - 1));

        SetupStartGameTimer();
    }
    else
    {
        // TODO: start game logic
        UE_LOG(LogTemp, Display, TEXT("StartGame!"));
        SetupItemDropTimer(2.5f, false, false);
    }
}

void ATetrisGameMode::SetupItemDropTimer(float Interval, bool bLoop, bool bStartNow)
{
    UE_LOG(LogTemp, Display, TEXT("ATetrisGameMode::SetupItemDropTimer()"));
    ItemDropInterval = Interval;

    auto world = GetWorld();
    world->GetTimerManager().SetTimer(ItemDropTimer, ItemDropDelegate,
        ItemDropInterval, bLoop, bStartNow ? 0 : -1.0f);
}

void ATetrisGameMode::OnItemDropTimer()
{
    UE_LOG(LogTemp, Display, TEXT("ATetrisGameMode::OnItemDropTimer()"));

    StartGame();
}

void ATetrisGameMode::PreStartGame(int32 count, int32 maxCount)
{
    if (count == 0)
    {
        auto world = GetWorld();
        FVector Pos(20 * 100, 10 * 100 / 2, 122);
        //auto ItemClass = ItemClasses[FString("T")];
        auto ItemClass = ItemClasses[FString("L")];
        CurrentItem = Cast<AItemBase>(world->SpawnActor(ItemClass, &Pos));
        CurrentItem->SetTileStatus();
    }
}

void ATetrisGameMode::StartGame()
{
    TArray<AActor*> detachedActors;
    CurrentItem->Ungroup(GameField, detachedActors);
    DetachedActors = detachedActors;
    DetachedActors[0]->SetActorLocation(DetachedActors[0]->GetActorLocation() + FVector(10, 10, 10));
}



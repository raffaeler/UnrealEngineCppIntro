// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBase.h"
#include "Helpers.h"

#include "BlocksManager.generated.h"

/**
 *
 */
UCLASS()
class TETRIS_API UBlocksManager : public UObject
{
    GENERATED_BODY()

private:
    int32 Rows;
    int32 Columns;
    int32 ItemSize;
    FVector Zero;

    // The floor tiles are stored as a matrix
    // 0,0 is the upper left tile
    TArray<TTuple<int32, AActor*>> Floor;

public:
    void InitializeBlocks(int32 FieldRows, int32 FieldColumns, int32 ShapItemSize, const FVector& PositionZero);
    __forceinline FVector GetLocationByXY(int32 X, int32 Y);
    __forceinline TTuple<int32, int32> GetXYByLocation(const FVector& Location);
    __forceinline int32 GetFloorIndexByXY(int32 x, int32 y) const;
    void ResetFloor();
    bool UpdateFloor(int32 X, int32 Y, int32 Rot, AItemBase* Item);
    void CrystalizeFloor(AItemBase* Item, AActor* NewParent);
    void DumpFloor();




    //private:
    //	TArray<TArray<AActor*>> Blocks;
    //
    //	int32 Rows;
    //	int32 Columns;
    //
    //	void EnsureMemoryBlocks();
    //
    //public:
    //	void InitializeBlocks(int32 Rows, int32 Columns);
    //
    //	void SetBlock(int Row, int Column, AActor* Actor);
    //	TArray<AActor*> RemoveLine(int Line);
};

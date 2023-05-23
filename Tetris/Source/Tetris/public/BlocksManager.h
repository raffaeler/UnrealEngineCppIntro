// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//#include "Templates/Tuple.h"
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
    //UPROPERTY()
    TArray<TTuple<int32, AActor*>> Floor;
    void DeleteAndShift(int32 Row, bool DoRemove, TArray<AActor*>& Removed, TArray<AActor*>& Shifted);

public:
    void InitializeBlocks(int32 FieldRows, int32 FieldColumns, int32 ShapItemSize, const FVector& PositionZero);
    __forceinline FVector GetLocationByXY(int32 X, int32 Y);
    __forceinline TTuple<int32, int32> GetXYByLocation(const FVector& Location);
    __forceinline int32 GetFloorIndexByXY(int32 x, int32 y) const;
    __forceinline TTuple<int32, int32> GetXYByFloorIndex(int32 index) const;

    void ResetFloor();
    bool UpdateFloor(int32 X, int32 Y, int32 Rot, AItemBase* Item);
    void CrystalizeFloor(AItemBase* Item, AActor* NewParent,
        TArray<AActor*>& Removed, TArray<AActor*>& Shifted);
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


/*
  Crystalization effect: example 1

  Item moving          Item still           Blocks removed

  |0123456789|         |0123456789|         |0123456789|
 0|          |        0|          |        0|          |
 1|          |        1|          |        1|          |
 2|          |        2|          |        2|          |
 3|          |        3|          |        3|          |
 4|          |        4|          |        4|          |
 5|          |        5|          |        5|          |
 6|          |        6|          |        6|          |
 7|          |        7|          |        7|          |
 8|          |        8|          |        8|          |
 9|          |        9|          |        9|          |
10|          |       10|          |       10|          |
11|          |       11|          |       11|          |
12|          |       12|          |       12|          |
13|          |       13|          |       13|          |
14|          |       14|          |       14|          |
15|          |       15|          |       15|          |
16|          |       16|          |       16|          |
17|STTTL  *T |       17|STTTL  LT |       17|          |
18|SSTLL***TT|       18|SSTLLLLLTT|       18|STTTL  LT |
19|JS LLLSSTL|       19|JS LLLSSTL|       19|JS LLLSSTL|
  |0123456789|         |0123456789|         |0123456789|




  Crystalization effect: example 2

  Item moving          Item still           Blocks removed

  |0123456789|         |0123456789|         |0123456789|
 0|          |        0|          |        0|          |
 1|          |        1|          |        1|          |
 2|          |        2|          |        2|          |
 3|          |        3|          |        3|          |
 4|          |        4|          |        4|          |
 5|          |        5|          |        5|          |
 6|          |        6|          |        6|          |
 7|          |        7|          |        7|          |
 8|          |        8|          |        8|          |
 9|          |        9|          |        9|          |
10|          |       10|          |       10|          |
11|          |       11|          |       11|          |
12|          |       12|          |       12|          |
13|          |       13|          |       13|          |
14|          |       14|          |       14|          |
15|          |       15|          |       15|          |
16|J       **|       16|J       LL|       16|          |
17|JJJ ZZ   *|       17|JJJ ZZ   L|       17|J       LL|
18|STTTLZZLT*|       18|STTTLZZLTL|       18|JJJ ZZ   L|
19|JS LLLSSTL|       19|JS LLLSSTL|       19|JS LLLSSTL|
  |0123456789|         |0123456789|         |0123456789|



*/
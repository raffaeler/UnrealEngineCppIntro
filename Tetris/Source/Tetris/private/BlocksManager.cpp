// Fill out your copyright notice in the Description page of Project Settings.


#include "BlocksManager.h"

//void UBlocksManager::InitializeBlocks(int32 Rows, int32 Columns)
//{
//    this->Rows = Rows;
//    this->Columns = Columns;
//    Blocks.Empty();
//    for (int32 i = 0; i < Rows; i++)
//    {
//        TArray<AActor*> Row;
//        for (int32 j = 0; j < Columns; j++)
//        {
//            Row[j] = nullptr;
//        }
//
//        Blocks.Push(Row);
//    }
//}
//
//void UBlocksManager::EnsureMemoryBlocks()
//{
//    auto missing = Rows - Blocks.Num();
//    if (missing < 0)
//    {
//        UE_LOG(LogTemp, Log, TEXT("Tetris> UBlocksManager::EnsureMemoryBlocks - too many rows"));
//        return;
//    }
//
//    for (int32 i = 0; i < missing; i++)
//    {
//        TArray<AActor*> Row;
//        for (int32 j = 0; j < Columns; j++)
//        {
//            Row[j] = nullptr;
//        }
//
//        Blocks.Push(Row);
//    }
//}
//
//void UBlocksManager::SetBlock(int Row, int Column, AActor* Actor)
//{
//    Blocks[Row][Column] = Actor;
//}
//
//TArray<AActor*> UBlocksManager::RemoveLine(int Line)
//{
//    TArray<AActor*> actors = Blocks[Line];
//    Blocks.RemoveAt(Line);
//    EnsureMemoryBlocks();
//    return actors;
//}

void UBlocksManager::InitializeBlocks(int32 FieldRows, int32 FieldColumns, int32 ShapeItemSize, const FVector& PositionZero)
{
    Rows = FieldRows;
    Columns = FieldColumns;
    ItemSize = ShapeItemSize;
    Zero = PositionZero;
    ResetFloor();
}

void UBlocksManager::ResetFloor()
{
    Floor.Empty();
    auto count = Rows * Columns;
    Floor.Reserve(count);
    for (int i = 0; i < count; i++)
    {
        Floor.Push({ 0, nullptr });
    }
}

int32 UBlocksManager::GetFloorIndexByXY(int32 x, int32 y) const
{
    return y * Columns + x;
}

FVector UBlocksManager::GetLocationByXY(int32 X, int32 Y)
{
    return FVector(X * 100 + Zero.X, Y * 100 + Zero.Y, Zero.Z);
}

TTuple<int32, int32> UBlocksManager::GetXYByLocation(const FVector& Location)
{
    int32 X = (int32)((Location.X - Zero.X) / 100);
    int32 Y = (int32)((Location.Y - Zero.Y) / 100);
    return { X, Y };
}

// X can span to negative beyond the field (negative values) because the
// matrix may have zeroes on the left and the leftmost tile of the item
// must be able to reach the 0 column.
// TileKind is a number < 100 representing the shape
// The matrix add 100 to the Tile Kind to represent the shape that is moving
bool UBlocksManager::UpdateFloor(int32 X, int32 Y, int32 Rot, AItemBase* Item)
{
    const FMatrix44f& Shape = Item->GetShape(Rot);
    EShapeKind ShapeKind = Item->GetShapeKind();

    int32 mx = 0;   // x coordinate of the shape matrix
    int32 my = 0;   // y coordinate of the shape matrix
    int32 mxF = 0;  // x offset of the shape matrix
    int32 myF = 0;  // y offset of the shape matrix

    TArray<TTuple<int32, int32>> Changes;
    Changes.Reserve(16);

    if (X < 0)
    {
        mxF = FMath::Abs(X);
        X = 0;
        if (mxF >= ItemSize) return false;

        // check if the Shape would collide with the left margin
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < mxF; c++)
            {
                if (Shape.M[r][c] != 0) return false;
            }
        }
    }

    if (Y < 0)
    {
        myF = FMath::Abs(Y);
        Y = 0;
        if (myF >= ItemSize) return false;

        // check if the Shape would collide with the bottom margin
        for (int c = ItemSize - 1; c >= myF; c--)
        {
            for (int r = 0; r < 4; r++)
            {
                if (Shape.M[r][c] != 0) return false;
            }
        }
    }

    my = myF;
    for (int j = Y; j < Y + ItemSize && my < ItemSize; j++)
    {
        mx = mxF;
        for (int i = X; i < X + ItemSize && mx < ItemSize; i++)
        {
            int32 index = GetFloorIndexByXY(i, j);
            bool isFilled = Shape.M[my][mx] != 0;

            if (isFilled)
            {
                if (i >= Columns) return false;    // found a tile beyond the right margin
                if (j >= Rows) return false;
                const int32 content = Floor[index].Key;
                if (content > 0 && content < 100) return false;    // tile is already busy
                Changes.Push({ index, (int32)ShapeKind });
            }

            mx++;
        }

        my++;
    }

    // If there are overlaps, the function already returned false
    // Otherwise Changes contains the list of indices to be overwritten

    // delete the current moving shape
    for (int i = 0; i < Floor.Num(); i++)
    {
        if (Floor[i].Key >= 100) Floor[i] = { 0, nullptr };
    }

    // draw the current moving shape in the updated position
    for (const auto& tp : Changes)
    {
        Floor[tp.Get<0>()] = { tp.Get<1>() + 100, Item };
    }

    return true;
}

void UBlocksManager::DumpFloor()
{
    FString dump = " \n  |0123456789|\n";
    dump.Reserve(Rows * Columns + 200);
    for (int j = 0; j < Rows; j++)
    {
        auto line = FString::FromInt(j);
        if (line.Len() == 1) dump += FString(" ");
        dump += line;
        dump += FString("|");

        for (int i = 0; i < Columns; i++)
        {
            int32 index = GetFloorIndexByXY(i, j);
            int32 value = Floor[index].Key;
            if (value >= 100)
            {
                if (Floor[index].Value == nullptr) dump += TEXT("&"); else
                dump += TEXT("*");
            }
            else
            {
                if (Floor[index].Value == nullptr) dump += TEXT("&"); else
                dump += Helpers::ToString((EShapeKind)value);
            }
        }

        dump += TEXT("|\n");
    }

    dump += "  |0123456789|";
    UE_LOG(LogTemp, Log, TEXT("%s"), *dump);
}

void UBlocksManager::CrystalizeFloor(AItemBase* Item, AActor* NewParent)
{
    // when a shape stops falling down, it gets crystalized
    for (int i = 0; i < Floor.Num(); i++)
    {
        int32& value = Floor[i].Key;
        if (value >= 100)
        {
            Floor[i] = { value - 100, Floor[i].Value };
        }
    }

    // shapes get ungrouped into simple blocks (cubes)
    int32 MinY = INT_MAX;
    int32 MaxY = 0;
    TArray<AActor*> Detached;
    Item->Ungroup(NewParent, Detached);

    if (Detached.IsEmpty())
    {
        UE_LOG(LogTemp, Log, TEXT("AGameField::CrystalizeFloor - Detached is empty"));
        return;
    }

    // ungrouped blocks are then added to the Blocks Manager to keep track of their position
    for (const auto actor : Detached)
    {
        auto XY = GetXYByLocation(actor->GetActorLocation());
        auto x = XY.Get<0>();
        auto y = XY.Get<1>();

        MinY = FMath::Min(MinY, y);
        MaxY = FMath::Max(MaxY, y);

        //BlocksManager->SetBlock(x, y, actor);
    }

    // Floor indexes are from top to bottom
    // Blocks indexes are from bottom to top (to ease shifting the actors)
    int32 start = Rows - MinY;
    int32 end = Rows - MaxY;

    // The Floor array is used to verify whether there are full lines to remove
    TArray<int32> FullRows;
    for (int j = start; j < end; j++)
    {
        int counter = 0;
        for (int i = 0; i < Columns; i++)
        {
            int32 index = GetFloorIndexByXY(i, j);
            int32 value = Floor[index].Key;

            if (value > 0) counter++;
        }

        if (counter == Columns)
        {
            // full row => to remove
            FullRows.Push(j);
        }
    }

    // full lines are removed from the BlocksManager
    for (auto row : FullRows)
    {
        int32 blockRow = Rows - row;
        //TArray<AActor*> removedActors = BlocksManager->RemoveLine(blockRow);
    }


}


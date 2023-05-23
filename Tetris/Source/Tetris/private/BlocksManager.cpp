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

void UBlocksManager::InitializeBlocks(int32 FieldRows, int32 FieldColumns, int32 ShapeItemSize,
    int32 BlockCubeSize, float BlockCubeScale, const FVector& PositionZero)
{
    Rows = FieldRows;
    Columns = FieldColumns;
    ItemSize = ShapeItemSize;
    CubeSize = BlockCubeSize;
    CubeScale = BlockCubeScale;
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

TTuple<int32, int32> UBlocksManager::GetXYByFloorIndex(int32 index) const
{
    int x = index / Columns;
    int y = index % Columns;
    return { x, y };
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
                if (Floor[index].Value == nullptr) dump += TEXT("$"); else
                    dump += TEXT("*");
            }
            else
            {
                EShapeKind kind = (EShapeKind)value;
                if (kind != EShapeKind::None && Floor[index].Value == nullptr) dump += TEXT("%"); else
                    dump += Helpers::ToString(kind);
            }
        }

        dump += TEXT("|\n");
    }

    dump += "  |0123456789|";
    UE_LOG(LogTemp, Log, TEXT("%s"), *dump);
}

void UBlocksManager::CrystalizeFloor(AItemBase* Item, AActor* NewParent,
    TArray<AActor*>& Removed, TArray<AActor*>& Shifted)
{
    // shapes get ungrouped into simple blocks (cubes)
    TArray<AActor*> Detached;
    Item->Ungroup(NewParent, Detached);

    // placing the simple blocks (cubes) into a map by their position (index of the floor array)
    TMap<int32, AActor*> PositionMap;
    for (auto actor : Detached)
    {
        actor->SetActorRotation(FRotator(0, 0, 0)); // remove any rotation
        auto XY = GetXYByLocation(actor->GetActorLocation());
        auto index = GetFloorIndexByXY(XY.Get<0>(), XY.Get<1>());
        PositionMap.Add(index, actor);

        UE_LOG(LogTemp, Log, TEXT("Tetris> UBlocksManager::DeleteAndShift - Detached[%f, %f]"),
            XY.Key, XY.Value);
    }

    // This is the crystalization:
    // replacing the * with the ShapeKind and
    // replacing the shape pointer with the block pointer
    // The loop is reversed because it's more probable the
    // items stay at the bottom of the game field
    int32 replacement = 0;
    int32 minIndex = INT_MAX;
    int32 maxIndex = 0;
    for (int i = Floor.Num() - 1; i >= 0; --i)
    {
        int32& value = Floor[i].Key;
        if (value >= 100)
        {
            AActor* newPointer = PositionMap[i];
            Floor[i] = { value - 100, newPointer };
            minIndex = FMath::Min(minIndex, i);
            maxIndex = FMath::Max(maxIndex, i);

            UE_LOG(LogTemp, Log, TEXT("Tetris> UBlocksManager::DeleteAndShift - ReplacedFloor[%d]"),
                i);

            replacement++;
            if (replacement == Detached.Num()) break;
        }
    }

    DumpFloor();

    // The Floor is now updated with the blocks and the new pointers
    int32 minRow = minIndex / Columns;
    int32 maxRow = maxIndex / Columns;

    // Find the complete rows in the minRow to maxRow range
    int32 row = minRow;
    TArray<int32> toRemove;
    while (row <= maxRow)
    {
        auto index = row * Columns;
        int isComplete = true;
        for (int i = 0; i < Columns; i++)
        {
            if (Floor[index + i].Key == 0)
            {
                isComplete = false;
                break;
            }
        }

        if (isComplete)
        {
            UE_LOG(LogTemp, Log, TEXT("Tetris> UBlocksManager::DeleteAndShift - RowToRemove[%d]"),
                row);

            toRemove.Push(row);
        }

        row++;
    }

    for (int i = 0; i < toRemove.Num(); i++)
    {
        DeleteAndShift(toRemove[i], true, Removed, Shifted);
    }

    DumpFloor();
}

void UBlocksManager::DeleteAndShift(int32 Row, bool DoRemove,
    TArray<AActor*>& Removed, TArray<AActor*>& Shifted)
{
    if (Row == 0) return;
    int32 startIndex = Row * Columns;
    int32 endIndex = startIndex + Columns;

    for (int i = startIndex; i < endIndex; i++)
    {
        if (DoRemove)
        {
            AActor* actor = Floor[i].Value;
            if (actor != nullptr)
            {
                Removed.Push(actor);
            }
            else
            {
                UE_LOG(LogTemp, Log, TEXT("Tetris> UBlocksManager::DeleteAndShift - actor is null: %d"), i);
            }
        }

        Floor[i] = Floor[i - Columns];  // shift
        AActor* shiftedActor = Floor[i].Value;
        AItemBase* shiftedItemBase = Cast<AItemBase>(Floor[i].Value);
        if (shiftedItemBase != nullptr)
        {
            auto XY = GetXYByFloorIndex(i); // These coordinates are reversed x/y
            shiftedItemBase->CandidateLocation = 
                GetLocationByXY(XY.Value, XY.Key) + FVector(CubeSize/2, CubeSize / 2, 0);
            Shifted.Push(shiftedActor);
        }
    }

    DeleteAndShift(Row - 1, false, Removed, Shifted);
}






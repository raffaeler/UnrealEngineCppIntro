// Fill out your copyright notice in the Description page of Project Settings.


#include "GameField.h"
//#include "InputMappingContext.h"
//#include "EnhancedInputSubsystems.h"
//#include "InputMappingContext.h"
//#include "EnhancedInputComponent.h"

#include "TetrisGameMode.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGameField::AGameField()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;


    // Camera settings
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
    StaticMeshComponent = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

    StaticMeshComponent->SetupAttachment(RootComponent);
    ArmComponent->SetupAttachment(StaticMeshComponent);
    CameraComponent->SetupAttachment(ArmComponent, USpringArmComponent::SocketName);

    //ArmComponent->SetRelativeLocationAndRotation(
    //    FVector(0.0f, 0.0f, 50.0f),
    //    FRotator(0.0f, 90.0f, 0.0f));
    //ArmComponent->TargetArmLength = 400.f;
    //ArmComponent->bEnableCameraLag = false;
    //ArmComponent->CameraLagSpeed = 3.0f;

    /*
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
    ////ArmComponent->SetupAttachment(RootComponent);
    //ArmComponent->SetAbsolute(true, true, true);
    //ArmComponent->SetRelativeLocationAndRotation(ArmLocation, ArmRotation);
    //ArmComponent->TargetArmLength = ArmLength;
    //ArmComponent->bEnableCameraLag = false;	// was true
    //ArmComponent->CameraLagSpeed = 0.0f;	// was 6.0f
    //ArmComponent->bDrawDebugLagMarkers = ShowDebug;
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraMain"));
    Camera->SetupAttachment(ArmComponent, USpringArmComponent::SocketName);
    // GameInstance = Cast<UPMGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

    */

    //auto mesh = Cast<UStaticMeshComponent>(GetRootComponent());
    //if (mesh == nullptr)
    //{
    //    mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GameFieldMesh"));
    //    SetRootComponent(mesh);
    //}


    //StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(
    //    TEXT("GameFieldMesh"));

    //UE_LOG(LogTemp, Display, TEXT("Tetris> AGameField::AGameField() StaticMesh is %s"), StaticMeshComponent == nullptr ? *FString("null") : *FString("ok"));

    //SetRootComponent(StaticMeshComponent);
    //RootComponent = StaticMeshComponent;

    PrimaryMaterial = nullptr;
    MovementDuration = 0.3f;
    ItemFallDuration = 0.5f;

}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
    Super::BeginPlay();

    DbgDraw();

    UE_LOG(LogTemp, Display, TEXT("Tetris> AGameField Primary material:%s"),
        *(PrimaryMaterial->GetFName().ToString()));

    //auto mesh = Helpers::GetRootMeshComponent(this);
    //mesh->SetMaterial(0, PrimaryMaterial);

    //FMatrix44f La = FMatrix44f(
    //    FPlane4f(1, 1, 1, 0),
    //    FPlane4f(1, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Lb = FMatrix44f(
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Lc = FMatrix44f(
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(1, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Ld = FMatrix44f(
    //    FPlane4f(1, 1, 0, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));


    //FMatrix44f Ja = FMatrix44f(
    //    FPlane4f(1, 1, 1, 0),
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Jb = FMatrix44f(
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Jc = FMatrix44f(
    //    FPlane4f(1, 0, 0, 0),
    //    FPlane4f(1, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Jd = FMatrix44f(
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(1, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));


    //FMatrix44f Ia = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(1, 1, 1, 1),
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Ib = FMatrix44f(
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 1, 0));

    //FMatrix44f Ic = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(1, 1, 1, 1),
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Id = FMatrix44f(
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 1, 0));


    //FMatrix44f Oa = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Ob = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Oc = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Od = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0));


    //FMatrix44f Za = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(1, 1, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Zb = FMatrix44f(
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Zc = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(1, 1, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Zd = FMatrix44f(
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));


    //FMatrix44f Sa = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(1, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Sb = FMatrix44f(
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Sc = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(1, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Sd = FMatrix44f(
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 0, 1, 0),
    //    FPlane4f(0, 0, 0, 0));


    //FMatrix44f Ta = FMatrix44f(
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(1, 1, 1, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Tb = FMatrix44f(
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 1, 1, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Tc = FMatrix44f(
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(1, 1, 1, 0),
    //    FPlane4f(0, 0, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //FMatrix44f Td = FMatrix44f(
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(1, 1, 0, 0),
    //    FPlane4f(0, 1, 0, 0),
    //    FPlane4f(0, 0, 0, 0));

    //L.Push(La);
    //L.Push(Lb);
    //L.Push(Lc);
    //L.Push(Ld);

    //J.Push(Ja);
    //J.Push(Jb);
    //J.Push(Jc);
    //J.Push(Jd);

    //I.Push(Ia);
    //I.Push(Ib);
    //I.Push(Ic);
    //I.Push(Id);

    //O.Push(Oa);
    //O.Push(Ob);
    //O.Push(Oc);
    //O.Push(Od);

    //Z.Push(Za);
    //Z.Push(Zb);
    //Z.Push(Zc);
    //Z.Push(Zd);

    //S.Push(Sa);
    //S.Push(Sb);
    //S.Push(Sc);
    //S.Push(Sd);

    //T.Push(Ta);
    //T.Push(Tb);
    //T.Push(Tc);
    //T.Push(Td);

    ResetFloor();
}

// Called every frame
void AGameField::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Current != nullptr)
    {
        FVector From = Current->GetActorLocation();
        FVector To = From + FVector(0, 0, 200);

        DrawDebugDirectionalArrow(GetWorld(),
            From, To, 50, FColor::Yellow, false, -1, 0, 2);

        FVector From2 = Current->GetActorLocation() + FVector(100, 100, 0);
        FVector To2 = From2 + FVector(0, 0, 200);

        DrawDebugDirectionalArrow(GetWorld(),
            From2, To2, 50, FColor::Red, false, -1, 0, 2);


    }
}

void AGameField::DbgDraw()
{
    auto world = GetWorld();

    FVector Location1(0.1, 0.1, 100);
    FVector Location2(0.5, 0.5, 100);
    FVector Location3(0.1, 100, 100);
    FVector ZZ(0, 0, 100);

    //DrawDebugPoint(world, Location1, 50, FColor(0, 200, 200), true);

    FVector center(1000 / 2, 2000 / 2, 100);
    DrawDebugCylinder(world, center, center + FVector(0, 0, 400), 10, 100, FColor::Blue, true, -1, 0, 2);

    //DrawDebugDirectionalArrow(world,
    //    Location1, Location1 + ZZ, 50, FColor::Red, true, -1, 0, 2);
    //DrawDebugDirectionalArrow(world,
    //    Location2, Location2 + ZZ, 50, FColor::Green, true, -1, 0, 2);

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            FVector From(i * 100, j * 100, 100);
            FVector To = From + ZZ;

            DrawDebugDirectionalArrow(world,
                From, To, 50, FColor::Blue, true, -1, 0, 2);

            FString t = FString::FromInt(j) + "," + FString::FromInt(i);
            // Max 128 DrawDebugString but can be modified
            if (i % 2 == 0 && j % 2 == 0)
            {
                DrawDebugString(world, To, t, 0, FColor::Yellow, -1, false, 1.0f);
            }
        }
    }
}

#pragma region Enhanced Input managed inside the Pawn
// Called to bind functionality to input
void AGameField::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::SetupPlayerInputComponent()"));

    //// Get the player controller (either the default or the user-defined)
    //APlayerController* PC = Cast<APlayerController>(GetController());

    ////// Get the local player subsystem
    //UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

    //Subsystem->ClearAllMappings();    // remove existing bindings
    //Subsystem->AddMappingContext(InputMapping, 0);

    //// Define the new bindings using the EnhancedInput
    //UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    //// Bind the actions
    //PEI->BindAction(InputNewItem, ETriggerEvent::Triggered, this, &AGameField::OnNewItem);
}

//void AGameField::OnNewItem(const FInputActionValue& Value)
//{
//    if (Controller == nullptr)
//    {
//        UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Controller is null"));
//        return;
//    }
//
//    if (Value.GetValueType() != EInputActionValueType::Boolean)
//    {
//        UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Value must be a boolean"));
//        return;
//    }
//
//    bool value = Value.GetMagnitude() != 0;
//    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Value:%s"),
//        value ? TEXT("On") : TEXT("Off"));
//}

#pragma endregion

void AGameField::StartGame()
{
    //ATetrisGameMode* GameMode = Cast<ATetrisGameMode>(GetWorld()->GetAuthGameMode());
    //auto world = GetWorld();
    //FVector Pos(350, 50, 122);
    //FRotator Rotator;// (0, -90, 0);
    ////auto ItemClass = GameMode->ItemClasses[FString("I")];
    ////auto ItemClass = GameMode->ItemClasses[FString("J")];
    ////auto ItemClass = GameMode->ItemClasses[FString("L")];
    ////auto ItemClass = GameMode->ItemClasses[FString("O")];
    ////auto ItemClass = GameMode->ItemClasses[FString("S")];
    ////auto ItemClass = GameMode->ItemClasses[FString("T")];
    //auto ItemClass = GameMode->ItemClasses[FString("Z")];
    //Current = Cast<AItemBase>(world->SpawnActor(ItemClass, &Pos, &Rotator));
    //Current->SetTileStatus();
    //TargetLocation = Current->GetActorLocation();

    StartItemFallTimer();
}

int32 AGameField::GetFloorIndexByXY(int32 x, int32 y) const
{
    return y * Columns + x;
}

void AGameField::ResetFloor()
{
    Floor.Empty();
    auto count = Rows * Columns;
    Floor.Reserve(count);
    for (int i = 0; i < count; i++)
    {
        Floor.Push(0);
    }
}

FVector AGameField::GetLocationByXY(int32 X, int32 Y)
{
    return FVector(X * 100 + Zero.X, Y * 100 + Zero.Y, Zero.Z);
}

// X can span to negative beyond the field (negative values) because the
// matrix may have zeroes on the left and the leftmost tile of the item
// must be able to reach the 0 column.
// TileKind is a number < 100 representing the shape
// The matrix add 100 to the Tile Kind to represent the shape that is moving
bool AGameField::UpdateFloor(int32 X, int32 Y, const FMatrix44f& Shape, EShapeKind ShapeKind)
{
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
                const int32 content = Floor[index];
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
        if (Floor[i] >= 100) Floor[i] = 0;
    }

    // draw the current moving shape in the updated position
    for (const auto& tp : Changes)
    {
        Floor[tp.Get<0>()] = tp.Get<1>() + 100;
    }

    return true;
}

void AGameField::CrystalizeFloor()
{
    for (int i = 0; i < Floor.Num(); i++)
    {
        int32& value = Floor[i];
        if (value >= 100)
        {
            Floor[i] = value - 100;
        }
    }

    //Current->Ungroup()
}

void AGameField::DumpFloor()
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
            int32 value = Floor[index];
            if (value >= 100)
            {
                dump += TEXT("*");
            }
            else
            {
                dump += Helpers::ToString((EShapeKind)value);
            }
        }

        dump += TEXT("|\n");
    }

    dump += "  |0123456789|";
    UE_LOG(LogTemp, Log, TEXT("%s"), *dump);

}


void AGameField::OnLeft()
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnLeft()"));
    if (Current == nullptr) return;

    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    XC--;
    if (UpdateFloor(XC, YC, Current->GetShape(Rot), Current->GetShapeKind()))
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        DumpFloor();

        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = GetLocationByXY(XC, YC);
        //TargetLocation = TargetLocation - FVector(100, 0, 0);
        if (!IsMovementTimerRunning())
        {
            StartMovementTimer();
        }
    }
    else
    {
        XC++;
    }
}

void AGameField::OnRight()
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnRight()"));
    if (Current == nullptr) return;

    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    XC++;
    if (UpdateFloor(XC, YC, Current->GetShape(Rot), Current->GetShapeKind()))
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        DumpFloor();

        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = GetLocationByXY(XC, YC);
        //TargetLocation = TargetLocation + FVector(100, 0, 0);
        if (!IsMovementTimerRunning())
        {
            StartMovementTimer();
        }
    }
    else
    {
        XC--;
    }
}

void AGameField::OnRotate()
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnRotate()"));
    if (Current == nullptr) return;

    //if (GetWorld()->GetTimerManager().IsTimerActive(MovementTimer)) {
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    Rot++;
    if (Rot == 4) Rot = 0;
    if (UpdateFloor(XC, YC, Current->GetShape(Rot), Current->GetShapeKind()))
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        DumpFloor();

        FVector PreOffset;
        FVector PostOffset;
        FRotator Rotator;
        Current->GetLocationAndRotatorbyRotation(Rot, &PreOffset, &Rotator, &PostOffset);

        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = GetLocationByXY(XC, YC);
        TargetRotation = Rotator;
        TargetPostOffset = PostOffset;
        if (!IsMovementTimerRunning())
        {
            StartMovementTimer();
        }


        //UE_LOG(LogTemp, Log, TEXT("Tetris> StartLoc=(%f, %f, %f) - StartRot=(%f, %f, %f)"),
        //    StartLocation.X, StartLocation.Y, StartLocation.Z,
        //    StartRotation.Pitch, StartRotation.Yaw, StartRotation.Roll);

        //UE_LOG(LogTemp, Log, TEXT("Tetris> TargetLoc=(%f, %f, %f) - TargetRot=(%f, %f, %f)"),
        //    TargetLocation.X, TargetLocation.Y, TargetLocation.Z,
        //    TargetRotation.Pitch, TargetRotation.Yaw, TargetRotation.Roll);


        //StartMovementTimer();

        //FVector Location;
        //FRotator Rotator;
        //Current->GetLocationAndRotatorbyRotation(Rot, &Location, &Rotator);
        //Location += Current->GetActorLocation();
        //Current->SetActorLocationAndRotation(Location, Rotator);
    }
    else
    {
        Rot--;
        if (Rot < 0) Rot = 3;
    }
}

void AGameField::OnDrawNext()
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnDrawNext()"));
    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    YC++;
    if (UpdateFloor(XC, YC, Current->GetShape(Rot), Current->GetShapeKind()))
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        DumpFloor();
        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = GetLocationByXY(XC, YC);
        //TargetLocation = TargetLocation + FVector(0, 100, 0);
        if (!IsMovementTimerRunning())
        {
            StartMovementTimer();
        }
    }
    else
    {
        YC--;
    }
}

void AGameField::OnSpeedUp()
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnSpeedUp()"));
    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    if (Current != nullptr) Current->Destroy();
    Current = CreateItem((EShapeKind)ItemCounter, 0, 0);
    ItemCounter++;

    if (ItemCounter - 1 == (int32)EShapeKind::MAX) ItemCounter = (int32)EShapeKind::MIN;
}

void AGameField::OnDrop()
{
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnDrop()"));
    if (Current == nullptr) return;

    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    auto Loc = FVector(100, 100, 0);//Current->GetActorLocation();
    Temp = Loc;
    auto Back = FVector(-Loc.X, -Loc.Y, Loc.Z);
    //if (counter == 0) Current->AddActorWorldOffset(Back);
    //if (counter == 1) Current->AddActorWorldRotation(FRotator(0, -90, 0));
    //if (counter == 2) Current->AddActorWorldOffset(Temp);

    if (counter == 0) Current->TetrisRotate(counter);
    if (counter == 1) Current->TetrisRotate(counter);
    if (counter == 2) Current->TetrisRotate(counter);
    if (counter == 3)
    {
        Current->TetrisRotate(counter);
        counter = 0;
    }
    else
    {
        counter++;
    }

    //Current->AddActorLocalRotation
    //Current->AddActorLocalOffset
    //Current->AddActorWorldOffset
    //Current->AddActorWorldRotation
    
    //AActor::AddActorWorldRotation()

    ResetFloor();
}

void AGameField::StartMovementTimer()
{
    GetWorld()->GetTimerManager().SetTimer(
        MovementTimer,
        this,
        &AGameField::OnMovement,
        GetWorld()->GetDeltaSeconds(),
        true);
}

bool AGameField::IsMovementTimerRunning()
{
    return GetWorld()->GetTimerManager().IsTimerActive(MovementTimer);
}

void AGameField::CancelMovementTimer()
{
    GetWorld()->GetTimerManager().ClearTimer(MovementTimer);
}

void AGameField::OnMovement()
{
    //UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnMovement()"));
    if (Current == nullptr)
    {
        CancelMovementTimer();
        return;
    }

    CurrentTime += GetWorld()->GetDeltaSeconds();

    auto TotalTargetLocation = TargetLocation + TargetPostOffset;
    float Alpha = FMath::Clamp(CurrentTime / MovementDuration, 0.0f, 1.0f);
    FVector NewLocation = FMath::Lerp(StartLocation, TotalTargetLocation, Alpha);
    FRotator NewRotation = FMath::Lerp(StartRotation, TargetRotation, Alpha);

    //UE_LOG(LogTemp, Log, TEXT("Tetris> NewLoc=(%f, %f, %f) - NewRot=(%f, %f, %f)"),
    //    NewLocation.X, NewLocation.Y, NewLocation.Z,
    //    NewRotation.Pitch, NewRotation.Yaw, NewRotation.Roll);

    // Set the new rotation for the actor
    Current->SetActorLocationAndRotation(NewLocation, NewRotation);

    // Check if the animation is finished
    if (CurrentTime >= MovementDuration)
    {
        // Stop the animation timer
        CancelMovementTimer();
    }
}

void AGameField::StartItemFallTimer()
{
    GetWorld()->GetTimerManager().SetTimer(
        ItemFallTimer,
        this,
        &AGameField::OnItemFall,
        ItemFallDuration,
        false);
}

bool AGameField::IsItemFallTimerRunning()
{
    return GetWorld()->GetTimerManager().IsTimerActive(ItemFallTimer);
}

void AGameField::CancelItemFallTimer()
{
    GetWorld()->GetTimerManager().ClearTimer(ItemFallTimer);
}

AItemBase* AGameField::CreateItem(const EShapeKind ShapeKind, int Y, int X)
{
    XC = X;
    YC = Y;
    Rot = 0;

    ATetrisGameMode* GameMode = Cast<ATetrisGameMode>(GetWorld()->GetAuthGameMode());
    FString ShapeName = Helpers::ToString(ShapeKind);
    auto ItemClass = GameMode->ItemClasses[ShapeName];
    auto InitialPosition = GetLocationByXY(XC, YC);
    auto Item = Cast<AItemBase>(GetWorld()->SpawnActor(ItemClass));
    FVector PreOffset;
    FRotator Rotator;
    FVector PostOffset;
    Item->GetLocationAndRotatorbyRotation(Rot, &PreOffset, &Rotator, &PostOffset);
    Item->SetActorLocationAndRotation(InitialPosition, Rotator);
    Item->SetTileStatus();

    TargetLocation = PreOffset;
    TargetRotation = Rotator;
    TargetPostOffset = PostOffset;

    return Item;
}

AItemBase* AGameField::CreateRandomItem(int X, int Y)
{
    int32 index = FMath::RandRange((int32)EShapeKind::MIN, (int32)EShapeKind::MAX);
    return CreateItem((EShapeKind)index, X, Y);
}

void AGameField::OnItemFall()
{
    if (Current == nullptr)
    {
        // spawn new item
        CancelMovementTimer();
        Current = CreateRandomItem(0, 0);
    }
    else
    {
        // move the item down
        YC++;
        if (UpdateFloor(XC, YC, Current->GetShape(Rot), Current->GetShapeKind()))
        {
            // Item can go down
            UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
            DumpFloor();
            CurrentTime = 0.0f;
            StartLocation = Current->GetActorLocation();
            StartRotation = Current->GetActorRotation();
            TargetLocation = GetLocationByXY(XC, YC);
            //TargetLocation = TargetLocation + FVector(0, 100, 0);
            if (!IsMovementTimerRunning())
            {
                StartMovementTimer();
            }
        }
        else
        {
            YC--;
            // Item cannot go down
            // Finalize the location/rotation despite the ongoing animation
            CancelMovementTimer();
            Current->SetActorLocationAndRotation(TargetLocation + TargetPostOffset, TargetRotation);
            CrystalizeFloor();
            Current = nullptr;
        }
    }

    StartItemFallTimer();
}


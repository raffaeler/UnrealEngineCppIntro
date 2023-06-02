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
    ItemMaterialKind = EMaterialKind::Primary;
    MovementDuration = 0.3f;
    ItemFallDuration = 0.5f;

}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
    Super::BeginPlay();

    //DbgDraw();

    //UE_LOG(LogTemp, Display, TEXT("Tetris> AGameField Primary material:%s"),
    //    *(PrimaryMaterial->GetFName().ToString()));

    BlocksManager = NewObject<UBlocksManager>();
    BlocksManager->InitializeBlocks(Rows, Columns, ItemSize, CubeSize, CubeScale, Zero);

    BlocksManager->ResetFloor();
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
            From, To, 50, FColor::Red, false, -1, 0, 4);

        //FVector From2 = Current->GetActorLocation() + FVector(100, 100, 0);
        //FVector To2 = From2 + FVector(0, 0, 200);

        //DrawDebugDirectionalArrow(GetWorld(),
        //    From2, To2, 50, FColor::Yellow, false, -1, 0, 2);
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
    StartItemFallTimer();
}


void AGameField::OnLeft()
{
    if (Current == nullptr) return;
    //UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnLeft()"));

    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    XC--;
    if (BlocksManager->UpdateFloor(XC, YC, Rot, Current))
    {
        //UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        BlocksManager->DumpFloor();

        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = BlocksManager->GetLocationByXY(XC, YC);
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
    if (Current == nullptr) return;
    //UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnRight()"));

    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    XC++;
    if (BlocksManager->UpdateFloor(XC, YC, Rot, Current))
    {
        //UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        BlocksManager->DumpFloor();

        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = BlocksManager->GetLocationByXY(XC, YC);
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
    if (Current == nullptr) return;
    //UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnRotate()"));

    //if (GetWorld()->GetTimerManager().IsTimerActive(MovementTimer)) {
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    Rot++;
    if (Rot == 4) Rot = 0;
    if (BlocksManager->UpdateFloor(XC, YC, Rot, Current))
    {
        //UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        BlocksManager->DumpFloor();

        FVector PreOffset;
        FVector PostOffset;
        FRotator Rotator;
        Current->GetLocationAndRotatorbyRotation(Rot, &PreOffset, &Rotator, &PostOffset);

        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = BlocksManager->GetLocationByXY(XC, YC);
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
    }
    else
    {
        Rot--;
        if (Rot < 0) Rot = 3;
    }
}

void AGameField::OnDrawNext()
{
    //UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnDrawNext()"));

    //if (IsMovementTimerRunning())
    //{
    //    CancelMovementTimer();
    //    Current->SetActorLocationAndRotation(TargetLocation, TargetRotation);
    //}

    YC++;
    if (BlocksManager->UpdateFloor(XC, YC, Rot, Current))
    {
        //UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
        BlocksManager->DumpFloor();
        CurrentTime = 0.0f;
        StartLocation = Current->GetActorLocation();
        StartRotation = Current->GetActorRotation();
        TargetLocation = BlocksManager->GetLocationByXY(XC, YC);

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
    //UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnSpeedUp()"));

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
    if (Current == nullptr) return;
    //UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnDrop()"));

    do
    {
        YC++;
    } while (BlocksManager->UpdateFloor(XC, YC, Rot, Current));

    YC--;
    BlocksManager->DumpFloor();
    CurrentTime = 0.0f;
    StartLocation = Current->GetActorLocation();
    StartRotation = Current->GetActorRotation();
    TargetLocation = BlocksManager->GetLocationByXY(XC, YC);
    TargetRotation = StartRotation;
    if (!IsMovementTimerRunning())
    {
        StartMovementTimer();
    }

    //Current->AddActorLocalRotation
    //Current->AddActorLocalOffset
    //Current->AddActorWorldOffset
    //Current->AddActorWorldRotation

    //AActor::AddActorWorldRotation()

    //BlocksManager->ResetFloor();
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
    auto InitialPosition = BlocksManager->GetLocationByXY(XC, YC);
    auto Item = Cast<AItemBase>(GetWorld()->SpawnActor(ItemClass));
    FVector PreOffset;
    FRotator Rotator;
    FVector PostOffset;
    Item->GetLocationAndRotatorbyRotation(Rot, &PreOffset, &Rotator, &PostOffset);
    Item->SetActorLocationAndRotation(InitialPosition, Rotator);
    Item->SetTileStatus(ItemMaterialKind);

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
    bool startFallTimer = true;
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
        if (BlocksManager->UpdateFloor(XC, YC, Rot, Current))
        {
            // Item can go down
            //UE_LOG(LogTemp, Log, TEXT("Tetris> [%d,%d] R=%d"), XC, YC, Rot);
            BlocksManager->DumpFloor();
            CurrentTime = 0.0f;
            StartLocation = Current->GetActorLocation();
            StartRotation = Current->GetActorRotation();
            TargetLocation = BlocksManager->GetLocationByXY(XC, YC);
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

            UE_LOG(LogTemp, Display, TEXT("Tetris> Crystalize before:%f"),
                GetWorld()->GetDeltaSeconds());

            Removed.Empty();
            Shifted.Empty();
            BlocksManager->CrystalizeFloor(Current, this, Removed, Shifted);
            Current = nullptr;

            UE_LOG(LogTemp, Display, TEXT("Tetris> Crystalize after :%f"),
                GetWorld()->GetDeltaSeconds());

            if (!Removed.IsEmpty())
            {
                // 1. Cancel all the timers
                CancelItemFallTimer();
                CancelMovementTimer();
                startFallTimer = false;

                // 2. Start new animation with:
                //    - Removed Items collapsing
                //    - Shifted Items moving down to the CandidateLocation
                CurrentTime = 0;    // this is shared with MovementTimer because they do not run together
                CrushDuration = 1.5f;
                CrushingHeight = CubeSize * CubeScale;   // can take this from the bounds
                StartCrushTimer();

                // 3. Resume all the timers
                // This must be done with StartItemFallTimer() at the end of the animation
            }
        }
    }

    if (startFallTimer) StartItemFallTimer();
}

void AGameField::StartCrushTimer()
{
    GetWorld()->GetTimerManager().SetTimer(
        CrushTimer,
        this,
        &AGameField::OnCrush,
        GetWorld()->GetDeltaSeconds(),
        true);
}

bool AGameField::IsCrushTimerRunning()
{
    return GetWorld()->GetTimerManager().IsTimerActive(CrushTimer);
}

void AGameField::CancelCrushTimer()
{
    GetWorld()->GetTimerManager().ClearTimer(CrushTimer);
}

void AGameField::OnCrush()
{
    CurrentTime += GetWorld()->GetDeltaSeconds();

    // Check if the animation is finished
    if (CurrentTime >= CrushDuration)
    {
        // Stop the animation timer
        CancelCrushTimer();

        // Restart game
        StartItemFallTimer();
        return;
    }

    // Delta of time
    float Alpha = FMath::Clamp(CurrentTime / CrushDuration, 0.0f, 1.0f);

    // Removed items are crushed
    FVector scale;
    FVector newScale;
    float newHeight = 0.f;
    if (!Removed.IsEmpty())
    {
        // These vars can be computed once for all
        auto firstActor = Removed[0];
        scale = firstActor->GetActorRelativeScale3D();
        newScale = FMath::Lerp(scale, FVector(scale.X, 0.0f, scale.Z), Alpha);
        newHeight = newScale.Y * CubeSize;  // 100 is the size of our cube
    }

    // Below a certain scale the there is visual difference
    // therefore it's better to remove the items
    if (newScale.Y < 0.03f)
    {
        for (auto actor : Removed)
        {
            actor->Destroy();   // remove the crushed actors
        }

        Removed.Empty();
    }

    for (auto actor : Removed)
    {
        auto location = actor->GetActorLocation();
        auto newY = location.Y + (CrushingHeight - newHeight) / 2;

        actor->SetActorRelativeScale3D(newScale);
        actor->SetActorLocation(FVector(location.X, newY, location.Z));

        UE_LOG(LogTemp, Display, TEXT("Tetris> Crush-Removed Loc[%f,%f] New[%f,%f] Scale[%f,%f]"),
            location.X, location.Y,
            location.X, newY,
            newScale.X, newScale.Y);
    }

    CrushingHeight = newHeight;

    for (auto actor : Shifted)
    {
        auto itemBase = Cast<AItemBase>(actor);
        auto candidate = itemBase->CandidateLocation;
        auto location = actor->GetActorLocation();

        auto newLocation = FMath::Lerp(location, candidate, Alpha);
        actor->SetActorLocation(newLocation);

        UE_LOG(LogTemp, Display, TEXT("Tetris> Crush-Shifted Loc[%f,%f] New[%f,%f] Cand[%f,%f]"),
            location.X, location.Y,
            newLocation.X, newLocation.Y,
            candidate.X, candidate.Y);

    }


}


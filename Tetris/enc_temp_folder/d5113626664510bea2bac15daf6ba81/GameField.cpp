// Fill out your copyright notice in the Description page of Project Settings.


#include "GameField.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "DrawDebugHelpers.h"

#include "Helpers.h"

// Sets default values
AGameField::AGameField()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    
    // Camera settings
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
    StaticMeshComponent = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

    StaticMeshComponent->SetupAttachment(RootComponent);
    ArmComponent->SetupAttachment(StaticMeshComponent);
    CameraComponent->SetupAttachment(ArmComponent, USpringArmComponent::SocketName);

    ArmComponent->SetRelativeLocationAndRotation(
        FVector(0.0f, 0.0f, 50.0f),
        FRotator(0.0f, 90.0f, 0.0f));
    ArmComponent->TargetArmLength = 400.f;
    ArmComponent->bEnableCameraLag = false;
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
}

// Called every frame
void AGameField::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGameField::DbgDraw()
{
    auto world = GetWorld();

    FVector Location1(0.1, 0.1, 100);
    FVector Location2(0.5, 0.5, 100);
    FVector Location3(0.1, 100, 100);
    FVector Z(0, 0, 100);

    //DrawDebugPoint(world, Location1, 50, FColor(0, 200, 200), true);

    FVector center(2000 / 2, 1000 / 2, 100);
    DrawDebugCylinder(world, center, center + FVector(0, 0, 400), 10, 100, FColor::Blue, true, -1, 0, 2);

    //DrawDebugDirectionalArrow(world,
    //    Location1, Location1 + Z, 50, FColor::Red, true, -1, 0, 2);
    //DrawDebugDirectionalArrow(world,
    //    Location2, Location2 + Z, 50, FColor::Green, true, -1, 0, 2);

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            FVector From(j * 100, i * 100, 100);
            FVector To = From + Z;

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

// Called to bind functionality to input
void AGameField::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::SetupPlayerInputComponent()"));


    // Get the player controller
    APlayerController* PC = Cast<APlayerController>(GetController());

    //// Get the local player subsystem
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
    //// Clear out existing mapping, and add our mapping
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(InputMapping, 0);

    // Get the EnhancedInputComponent
    UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    // Bind the actions
    PEI->BindAction(InputNewItem, ETriggerEvent::Triggered, this, &AGameField::OnNewItem);

}

void AGameField::OnNewItem(const FInputActionValue& Value)
{
    if (Controller == nullptr)
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Controller is null"));
        return;
    }

    if (Value.GetValueType() != EInputActionValueType::Boolean)
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Value is not boolean"));
        return;
    }

    bool value = Value.GetMagnitude() != 0;
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Value:%s"),
        value ? TEXT("On") : TEXT("Off"));

}
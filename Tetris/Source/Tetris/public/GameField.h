// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "InputAction.h"
//#include "InputMappingContext.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"
#include <GameFramework/SpringArmComponent.h>
#include "Camera/CameraComponent.h"

#include "ItemBase.h"
#include "Helpers.h"

#include "GameField.generated.h"

UCLASS()
class TETRIS_API AGameField : public APawn
{
    GENERATED_BODY()

private:
    void DbgDraw();

public:
    // Sets default values for this pawn's properties
    AGameField();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region Enhanced Input managed inside the Pawn
    //protected:
    //	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
    //		class UInputMappingContext* InputMapping;
    //
    //	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
    //		UInputAction* InputNewItem;
    //
    //	void OnNewItem(const FInputActionValue& Value);
#pragma endregion

public:
    UPROPERTY(EditAnywhere, Category = "Tetris Components")
        UStaticMeshComponent* StaticMeshComponent = nullptr;

    // Camera related settings
    UPROPERTY(EditAnywhere, Category = "Tetris Components")
        UCameraComponent* CameraComponent = nullptr;

    UPROPERTY(EditAnywhere, Category = "Tetris Components")
        USpringArmComponent* ArmComponent = nullptr;

public:
    // Input Commands:
    void OnLeft();
    void OnRight();
    void OnRotate();
    void OnDrawNext();
    void OnSpeedUp();
    void OnDrop();

public:
    UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
        UMaterialInterface* PrimaryMaterial = nullptr;

public:
    void StartGame();
    UPROPERTY() AItemBase* Current;

private:
    // The floor tiles are stored as a matrix
    // 0,0 is the upper left tile
    FVector Zero = FVector(50, 50, 122);
    FVector GetLocationByXY(int32 X, int32 Y);
    TArray<int32> Floor;
    const int32 Rows = 20;
    const int32 Columns = 10;
    const int32 ItemSize = 4;	// 4x4
    __forceinline int32 GetFloorIndexByXY(int32 x, int32 y) const;
    void ResetFloor();
    bool UpdateFloor(int32 X, int32 Y, const FMatrix44f& Shape, EShapeKind ShapeKind);
    void CrystalizeFloor();
    void DumpFloor();

private:
    // RotateAround variables
    float AngleAxis;
    FVector Distance;
    FVector RotationAxis = FVector(0, 0, 1);	// Around Z
    float Multiplier = 1;
    void PrepareRotateAround();
    void RotateAround();

private:
    // debug
    int counter = 0;
    FVector Temp;

private:
    // Rotation animation
    FTimerHandle RotationTimer;
    void StartItemAnimationTimer();
    void OnAnimateRotation();
    FRotator StartRotation;
    FRotator TargetRotation;
    FVector StartLocation;
    FVector TargetLocation;
    FVector TargetPostOffset;

    float AnimationDuration;
    float CurrentTime;
    bool IsRotationTimerRunning;

private:
    // Item Fall Timer
    FTimerHandle ItemFallTimer;
    void StartItemFallTimer();
    void OnStartItemFall();
    bool IsItemFallTimerRunning();
    float ItemFallInterval;


private:
    int ItemCounter = (int32)EShapeKind::MIN;
    AItemBase* CreateRandomItem(int X, int Y);
    AItemBase* CreateItem(const EShapeKind ShapeKind, int X, int Y);

public:


    //TArray<FMatrix44f> L;
    //TArray<FMatrix44f> J;
    //TArray<FMatrix44f> I;
    //TArray<FMatrix44f> O;
    //TArray<FMatrix44f> Z;
    //TArray<FMatrix44f> S;
    //TArray<FMatrix44f> T;

    int32 XC = 3, YC = 0;
    int32 Rot = 0;


};

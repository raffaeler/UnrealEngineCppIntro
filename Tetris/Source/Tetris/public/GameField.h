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
#include "BlocksManager.h"
#include "Helpers.h"

#include "GameField.generated.h"

UCLASS()
class TETRIS_API AGameField : public APawn
{
    GENERATED_BODY()

private:
    void DbgDraw();

public:
    AGameField();

protected:
    virtual void BeginPlay() override;

    UPROPERTY()
        UBlocksManager* BlocksManager = nullptr;

public:
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
    UPROPERTY(Transient) AItemBase* Current = nullptr;

    EBlockMaterialKind ItemMaterialKind;

private:
    const int32 Rows = 20;
    const int32 Columns = 10;
    const int32 ItemSize = 4;	// 4x4
    const int32 CubeSize = 100;
    const float CubeScale = 0.95f;
    FVector Zero = FVector(0, 0, 122);

private:
    // debug variables
    int counter = 0;
    FVector Temp;

private:
    // Movement animation
    FTimerHandle MovementTimer;
    void StartMovementTimer();
    bool IsMovementTimerRunning();
    void CancelMovementTimer();
    void OnMovement();
    FRotator StartRotation;
    FRotator TargetRotation;
    FVector StartLocation;
    FVector TargetLocation;
    FVector TargetPostOffset;

    float MovementDuration;
    float CurrentTime;

private:
    // Item Fall Timer
    FTimerHandle ItemFallTimer;
    void StartItemFallTimer();
    bool IsItemFallTimerRunning();
    void CancelItemFallTimer();
    void OnItemFall();
    float ItemFallDuration;

private:
    TArray<AActor*> Removed;
    TArray<AActor*> Shifted;

    FTimerHandle CrushTimer;
    void StartCrushTimer();
    bool IsCrushTimerRunning();
    void CancelCrushTimer();
    void OnCrush();
    float CrushDuration;
    float CrushingHeight;


private:
    int ItemCounter = (int32)EShapeKind::None + 1;
    AItemBase* CreateRandomItem(int X, int Y);
    AItemBase* CreateItem(const EShapeKind ShapeKind, int X, int Y);

public:
    int32 XC = 3, YC = 0;
    int32 Rot = 0;

public:
    // Score and HUD
    void UpdateScore(int32 num);
    void UpdateHUD();
};

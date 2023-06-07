// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"

/*
Tetris original key mappings
7       Left
9       Right
8       Rotate
1       Draw Next
6       Speed Up
4       Drop
Space   Drop
*/


void ATetrisPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisPlayerController::SetupPlayerInputComponent()"));

    //UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("NewItem",
    //    EKeys::One));

    //InputComponent->BindAction("NewItem",
    //    IE_Pressed,
    //    this,
    //    &ATetrisPlayerController::OnNewItem);

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(InputMapping, 0);
    UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(InputComponent);
    PEI->BindAction(InputNewItem, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnNewItem);

    PEI->BindAction(InputLeft, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnLeft);
    PEI->BindAction(InputRight, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnRight);
    PEI->BindAction(InputRotate, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnRotate);
    PEI->BindAction(InputDrawNext, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnDrawNext);
    PEI->BindAction(InputSpeedUp, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnSpeedUp);
    PEI->BindAction(InputDrop, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnDrop);
    PEI->BindAction(MaterialSwitch, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnMaterialSwitch);

    //// Get the player controller
    //APlayerController* PC = Cast<APlayerController>(GetController());

    ////// Get the local player subsystem
    //UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
    ////// Clear out existing mapping, and add our mapping
    //Subsystem->ClearAllMappings();
    //Subsystem->AddMappingContext(InputMapping, 0);

    // Get the EnhancedInputComponent
    //UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(InputComponent);
    // Bind the actions
    //BindAction(InputNewItem, ETriggerEvent::Triggered, this, &ATetrisPlayerController::OnNewItem);

}

bool ATetrisPlayerController::ValidateInput(const FInputActionValue& InputValue)
{
    if (InputValue.GetValueType() != EInputActionValueType::Boolean)
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisPlayerController::OnNewItem() - Value must be a boolean"));
        return false;
    }

    return InputValue.GetMagnitude() != 0;
}

void ATetrisPlayerController::OnNewItem(const FInputActionValue& InputValue)
{
    bool value = ValidateInput(InputValue);
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Value:%s"),
        value ? TEXT("On") : TEXT("Off"));

    AActor* someone = GetPawn();
    if(someone != nullptr)
        UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisPlayerController - Pawn is %s"), *someone->GetName());
}

void ATetrisPlayerController::OnLeft(const FInputActionValue& InputValue)
{
    bool Value = ValidateInput(InputValue);

    auto GameField = Cast<AGameField>(GetPawn());
    if (Value) GameField->OnLeft();
}

void ATetrisPlayerController::OnRight(const FInputActionValue& InputValue)
{
    bool Value = ValidateInput(InputValue);

    auto GameField = Cast<AGameField>(GetPawn());
    if (Value) GameField->OnRight();
}

void ATetrisPlayerController::OnRotate(const FInputActionValue& InputValue)
{
    bool Value = ValidateInput(InputValue);

    auto GameField = Cast<AGameField>(GetPawn());
    if (Value) GameField->OnRotate();
}

void ATetrisPlayerController::OnDrawNext(const FInputActionValue& InputValue)
{
    bool Value = ValidateInput(InputValue);

    auto GameField = Cast<AGameField>(GetPawn());
    if (Value) GameField->OnDrawNext();
}

void ATetrisPlayerController::OnSpeedUp(const FInputActionValue& InputValue)
{
    bool Value = ValidateInput(InputValue);

    auto GameField = Cast<AGameField>(GetPawn());
    if (Value) GameField->OnSpeedUp();
}

void ATetrisPlayerController::OnDrop(const FInputActionValue& InputValue)
{
    bool Value = ValidateInput(InputValue);

    auto GameField = Cast<AGameField>(GetPawn());
    if (Value) GameField->OnDrop();
}

void ATetrisPlayerController::OnMaterialSwitch(const FInputActionValue& InputValue)
{
    bool Value = ValidateInput(InputValue);

    auto GameField = Cast<AGameField>(GetPawn());
    if (Value)
    {
        if(GameField->ItemMaterialKind == EBlockMaterialKind::Primary)
            GameField->ItemMaterialKind = EBlockMaterialKind::Secondary;
        else
            GameField->ItemMaterialKind = EBlockMaterialKind::Primary;
    }
}




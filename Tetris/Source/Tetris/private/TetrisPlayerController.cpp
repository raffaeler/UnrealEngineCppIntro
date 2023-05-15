// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"


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

void ATetrisPlayerController::OnNewItem(const FInputActionValue& Value)
{
    //if (Controller == nullptr)
    //{
    //    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Controller is null"));
    //    return;
    //}

    AActor* someone = GetPawn();
    //AActor* someone = GetParentActor();
    if(someone != nullptr)
        UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisPlayerController - Pawn is %s"), *someone->GetName());

    if (Value.GetValueType() != EInputActionValueType::Boolean)
    {
        UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Value is not boolean"));
        return;
    }

    bool value = Value.GetMagnitude() != 0;
    UE_LOG(LogTemp, Log, TEXT("Tetris> AGameField::OnNewItem() - Value:%s"),
        value ? TEXT("On") : TEXT("Off"));

}

//void ATetrisPlayerController::OnNewItem()
//{
//    //if (Controller == nullptr)
//    //{
//    //    UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisPlayerController::OnNewItem() - Controller is null"));
//    //    return;
//    //}
//
//    //if (Value.GetValueType() != EInputActionValueType::Boolean)
//    //{
//    //    UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisPlayerController::OnNewItem() - Value is not boolean"));
//    //    return;
//    //}
//
//    //bool value = Value.GetMagnitude() != 0;
//    //UE_LOG(LogTemp, Log, TEXT("Tetris> ATetrisPlayerController::OnNewItem() - Value:%s"),
//    //    value ? TEXT("On") : TEXT("Off"));
//
//}
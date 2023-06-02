// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "GameField.h"

#include "TetrisPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API ATetrisPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputNewItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputLeft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputRight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputRotate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputDrawNext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputSpeedUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputDrop;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* MaterialSwitch;

	bool ValidateInput(const FInputActionValue& InputValue);
	void OnNewItem(const FInputActionValue& InputValue);

	void OnLeft(const FInputActionValue& InputValue);
	void OnRight(const FInputActionValue& InputValue);
	void OnRotate(const FInputActionValue& InputValue);
	void OnDrawNext(const FInputActionValue& InputValue);
	void OnSpeedUp(const FInputActionValue& InputValue);
	void OnDrop(const FInputActionValue& InputValue);
	void OnMaterialSwitch(const FInputActionValue& InputValue);
};

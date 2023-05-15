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


};

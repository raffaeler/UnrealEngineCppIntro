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

	//UPROPERTY(EditAnywhere, Category = "TetrisInput")
	//	TSoftObjectPtr<UInputMappingContext> InputMapping;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tetris Enhanced Input")
		UInputAction* InputNewItem;

	void OnNewItem(const FInputActionValue& Value);


public:
	UPROPERTY(EditAnywhere, Category = "TetrisShape")
		UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* PrimaryMaterial = nullptr;

public:
	// Camera related settings
	UPROPERTY(EditAnywhere, Category = "TetrisCamera")
		UCameraComponent* CameraComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = "TetrisCamera")
		USpringArmComponent* ArmComponent = nullptr;


	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TetrisCamera")
	//	FVector ArmLocation;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TetrisCamera")
	//	FRotator ArmRotation;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TetrisCamera")
	//	float ArmLength = 400.0f;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TetrisCamera")
	//	float OrthWidth = 2400.0f;
};

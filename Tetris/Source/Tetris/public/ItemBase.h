// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class TETRIS_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* PrimaryMaterial = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* SecondaryMaterial = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* ExtraMaterial = nullptr;

	void SetTileStatus();
};

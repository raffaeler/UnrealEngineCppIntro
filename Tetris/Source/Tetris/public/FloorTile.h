// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorTile.generated.h"

UCLASS()
class TETRIS_API AFloorTile : public AActor
{
	GENERATED_BODY()
	
public:	
	AFloorTile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(EditAnywhere, Category="TetrisShape")
		UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category="TetrisShape")
		UMaterialInterface* PrimaryMaterial = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* SecondaryMaterial = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* ExtraMaterial = nullptr;
};

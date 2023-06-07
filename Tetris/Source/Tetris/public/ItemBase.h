// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Helpers.h"
#include "ItemBase.generated.h"

UCLASS()
class TETRIS_API AItemBase : public AActor
{
	GENERATED_BODY()

private:
	
public:	
	AItemBase();

	void ApplyMaterial(UMaterialInterface* material);
	bool Ungroup(AActor* NewParent, TArray<AActor*>& detachedActors);
	void Rotate();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* PrimaryMaterial = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* SecondaryMaterial = nullptr;

	UPROPERTY(EditAnywhere, Transient, Category = "TetrisShape")
		UMaterialInterface* ExtraMaterial = nullptr;

	void SetTileStatus(EBlockMaterialKind MaterialKind);

public:
	FMatrix44f Shape;
	FIntVector2 Center;
	int32 ExtentLeft = 0;
	int32 ExtentBottom = 0;
	int32 ExtentRight = 0;

	virtual FMatrix44f GetShape(int Rotation);
	virtual EShapeKind GetShapeKind();
	virtual bool GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset);
	void ShiftChildrenActors(FVector Offset);
	FVector CandidateLocation;

public:
	// Movements



};

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
	// Sets default values for this actor's properties
	AItemBase();

	void ApplyMaterial(UMaterialInterface* material);
	bool Ungroup(AActor* NewParent, TArray<AActor*>& detachedActors);
	//bool Ungroup2(AActor* NewParent, TArray<AActor*>& detachedActors);
	void Rotate();

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

	void SetTileStatus(EMaterialKind MaterialKind);

public:
	FMatrix44f Shape;
	FIntVector2 Center;
	int32 ExtentLeft;
	int32 ExtentBottom;
	int32 ExtentRight;

	virtual FMatrix44f GetShape(int Rotation);
	virtual EShapeKind GetShapeKind();
	virtual bool GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset);
	void ShiftChildrenActors(FVector Offset);
	virtual void TetrisRotate(int Rotation);
	FVector CandidateLocation;

public:
	// Movements



};

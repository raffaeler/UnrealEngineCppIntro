// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "TetrisWidget.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API UTetrisWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UTetrisWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

	void UpdateScore(int32 score);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* TBScore;
};

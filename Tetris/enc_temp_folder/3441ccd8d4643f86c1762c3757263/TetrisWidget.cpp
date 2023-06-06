// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisWidget.h"

UTetrisWidget::UTetrisWidget(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
}

void UTetrisWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

void UTetrisWidget::UpdateScore(int32 score)
{
    if (!TBScore)
        return;

    if (TBScore->Visibility == ESlateVisibility::Hidden)
    {
        TBScore->SetVisibility(ESlateVisibility::Visible);
    }
    
    auto str = FString::FromInt(score);
    auto text = FText::FromString(str);
    TBScore->SetText(text);
}


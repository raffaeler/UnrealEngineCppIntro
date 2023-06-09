// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisWidget.h"

UTetrisWidget::UTetrisWidget(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
}

void UTetrisWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if(HeartSizeAnimation)
        PlayAnimation(HeartSizeAnimation, 0.0f, 0);
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
    if (score == 0)
    {
        TBScore->SetText(FText());
    }
    else
    {
        TBScore->SetText(text);
        PlayAnimation(ScoreSizeAnimation, 0.0f, 1);
    }
}


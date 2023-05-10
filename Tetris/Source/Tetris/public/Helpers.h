// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TETRIS_API Helpers
{
public:
	Helpers();
	~Helpers();


	static UMaterialInterface* CreateTileMaterialByName(const FString& MaterialName)
	{
		FString materialName = FString("/Game/Blueprints/field/BP_") +
			MaterialName;

		UMaterialInterface* material = Cast<UMaterialInterface>(
			StaticLoadObject(UMaterialInterface::StaticClass(),
				nullptr,
				*materialName));

		return material;
	}
};

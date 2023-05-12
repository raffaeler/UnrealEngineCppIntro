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

	static UStaticMeshComponent* GetRootMeshComponent(AActor* element)
	{
		auto mesh = Cast<UStaticMeshComponent>(element->GetRootComponent());
		if (mesh == nullptr)
		{
			auto MeshName = element->GetName() + TEXT("Mesh");
			mesh = element->CreateDefaultSubobject<UStaticMeshComponent>(*MeshName);
			element->SetRootComponent(mesh);
		}

		return mesh;
	}

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

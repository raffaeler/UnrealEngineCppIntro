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
		auto root = element->GetRootComponent();
		auto mesh = Cast<UStaticMeshComponent>(root);
		UE_LOG(LogTemp, Display, TEXT("Tetris> Root: %s"), *element->GetName());
		if (mesh == nullptr)
		{
			//auto MeshName = element->GetName() + TEXT("Mesh");
			//mesh = element->CreateDefaultSubobject<UStaticMeshComponent>(*MeshName);
			//element->SetRootComponent(mesh);

			TArray<TObjectPtr<USceneComponent>> AllChildren;
			root->GetChildrenComponents(true, AllChildren);
			for (const auto& item : AllChildren)
			{
				UE_LOG(LogTemp, Display, TEXT("Tetris> Root Children: %s"), *item->GetName());
				
			}
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

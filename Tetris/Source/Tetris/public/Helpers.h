// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// the ordering numbers are important to index AfterWays variable
enum class EShapeKind : uint8
{
	None = 0,
	MIN = 1,
	L = 1,
	J = 2,
	Z = 3,
	S = 4,
	I = 5,
	O = 6,
	T = 7,
	MAX = 7,
};

/**
 * 
 */
class TETRIS_API Helpers
{
public:
	Helpers();
	~Helpers();

	template<typename TActor>
	static TActor* CloneActor(UWorld* world, TActor* actor)
	{
		auto actorClass = actor->GetClass();
		auto location = actor->GetActorLocation();
		auto transform = actor->GetTransform();
		auto mesh = Cast<UStaticMeshComponent>(
			actor->GetComponentByClass(UStaticMeshComponent::StaticClass()));
		auto material = mesh->GetMaterial(0);

		auto clone = Cast<TActor>(world->SpawnActor(actorClass, &location));
		clone->SetActorTransform(transform);
		clone->ApplyMaterial(material);
		return clone;
	}

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

			//TArray<TObjectPtr<USceneComponent>> AllChildren;
			//root->GetChildrenComponents(true, AllChildren);
			auto myComp = element->GetComponentByClass(UStaticMeshComponent::StaticClass());
			UE_LOG(LogTemp, Display, TEXT("Tetris> THE Child: %s"), *myComp->GetName());
			auto AllChildren = element->GetComponents();
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

	static FString ToString(const EShapeKind ShapeKind)
	{
		switch (ShapeKind)
		{
		case EShapeKind::None:
			return TEXT(" ");

		case EShapeKind::L:
			return TEXT("L");

		case EShapeKind::J:
			return TEXT("J");

		case EShapeKind::Z:
			return TEXT("Z");

		case EShapeKind::S:
			return TEXT("S");

		case EShapeKind::I:
			return TEXT("I");

		case EShapeKind::O:
			return TEXT("O");

		case EShapeKind::T:
			return TEXT("T");

		default:
			return TEXT(" ");
		}
	}


};

// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Helpers.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimaryMaterial = nullptr;
	SecondaryMaterial = nullptr;
	ExtraMaterial = nullptr;
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

}

void AItemBase::SetTileStatus()
{
	UE_LOG(LogTemp, Display, TEXT("Tetris> AItemBase Primary material:%s"),
		*(PrimaryMaterial->GetFName().ToString()));

	auto mesh = Helpers::GetRootMeshComponent(this);

	//mesh->SetMaterial(0, PrimaryMaterial);

	/*
	//StaticMeshComponent->SetMaterial(0, PrimaryMaterial);
	auto mesh = Cast<UStaticMeshComponent>(RootComponent);
	if (mesh != nullptr)
	{
		//static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(
		//	TEXT("StaticMesh'/Game/Meshes/SM_ItemI"));
		//UStaticMesh* Asset = MeshAsset.Object;

		//mesh->SetStaticMesh(Asset);


		mesh->SetMaterial(0, PrimaryMaterial);
		auto mat = mesh->GetMaterial(0);
		UE_LOG(LogTemp, Display, TEXT("Tetris> Read material:%s"),
			*(mat->GetFName().ToString()));
	}

	//StaticMeshComponent->SetMaterial(1, PrimaryMaterial);

	//FOutputDevice* OutputDevice = FGenericPlatformOutputDevices::GetLog();
	//StaticMeshComponent->LogMaterialsAndTextures(*OutputDevice, 0);
	*/
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


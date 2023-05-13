// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Helpers.h"
#include "Elements/Framework/TypedElementHandle.h"

// Sets default values
AItemBase::AItemBase()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //auto MeshName = GetName() + TEXT("Mesh");
    //auto mesh = CreateDefaultSubobject<UPrimitiveComponent>(*MeshName);
    //SetRootComponent(mesh);
    //GetMesh

    PrimaryMaterial = nullptr;
    SecondaryMaterial = nullptr;
    ExtraMaterial = nullptr;
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
    Super::BeginPlay();

}

void AItemBase::ApplyMaterial(UMaterialInterface* material)
{
    TArray<AActor*> AllChildren;
    GetAllChildActors(AllChildren);

    if (AllChildren.IsEmpty())
    {
        auto mesh = Cast<UStaticMeshComponent>(
            GetComponentByClass(UStaticMeshComponent::StaticClass()));

        UE_LOG(LogTemp, Display, TEXT("Tetris> Child:%s"),
            *(mesh->GetFName().ToString()));
        mesh->SetMaterial(0, material);
    }
    else
    {
        for (const auto& actor : AllChildren)
        {
            const auto& item = Cast<AItemBase>(actor);
            item->ApplyMaterial(material);
        }
    }
}

bool AItemBase::Ungroup(AActor* NewParent, TArray<AActor*>& detachedActors)
{
    //auto AllChildren = GetComponentsByClass(UChildActorComponent::StaticClass());
    TArray<UChildActorComponent*> AllChildren;
    GetComponents<UChildActorComponent>(AllChildren);
    if (AllChildren.IsEmpty()) return false;
    auto world = GetWorld();
    for (const auto& actorComponent : AllChildren)
    {
        auto childActorComponent = Cast<UChildActorComponent>(actorComponent);
        auto child = Cast<AItemBase>(childActorComponent->GetChildActor());

        //auto childClass = child->GetClass();
        //auto location = child->GetActorLocation();
        //auto transform = child->GetTransform();
        //auto mesh = Cast<UStaticMeshComponent>(
        //    child->GetComponentByClass(UStaticMeshComponent::StaticClass()));
        //auto material = mesh->GetMaterial(0);

        //auto newChild = Cast<AItemBase>(world->SpawnActor(childClass, &location));
        //newChild->SetActorTransform(transform);
        //newChild->ApplyMaterial(material);
        AItemBase* newChild = Helpers::CloneActor<AItemBase>(world, child);
        detachedActors.Push(newChild);
    }

    Destroy();
    return true;
}

bool AItemBase::Ungroup2(AActor* NewParent, TArray<AActor*>& detachedActors)
{
    //TArray<AActor*> AllChildren;
    //GetAllChildActors(AllChildren);
    auto AllChildren = GetComponentsByClass(UChildActorComponent::StaticClass());

    if (AllChildren.IsEmpty()) return false;

    for (const auto& actorComponent : AllChildren)
    {
        auto childActorComponent = Cast<UChildActorComponent>(actorComponent);
        //childActorComponent->DetachFromParent(true, true);// RemoveFromRoot();
        //childActorComponent->SetActive(false);
        auto child = childActorComponent->GetChildActor();
        child->AttachToActor(NewParent, FAttachmentTransformRules::KeepRelativeTransform);
        
        //UChildActorComponent* newComponent = NewObject<UChildActorComponent>(NewParent);
        //child->Atta
        //newComponent->Actor;
        //newComponent->RegisterComponent();
        //NewParent->

        //childActorComponent->UnregisterComponent();
        

        ////RemoveInstanceComponent(ChildActorComponents);
        ////child->RemoveFromRoot();
        ////child->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        detachedActors.Push(child);
    }

    TArray<AActor*> AllChildren2;
    AllChildren2.Empty();
    GetAllChildActors(AllChildren2);
    for (const auto& actor : AllChildren2)
    {
        const auto& item = Cast<AItemBase>(actor);
        UE_LOG(LogTemp, Display, TEXT("Tetris> AItemBase After detach:%s"),
            *(actor->GetFName().ToString()));
    }
    UE_LOG(LogTemp, Display, TEXT("Tetris> AItemBase Detached!"));
    //Destroy();
    return true;
}

void AItemBase::SetTileStatus()
{
    UE_LOG(LogTemp, Display, TEXT("Tetris> AItemBase Primary material:%s"),
        *(PrimaryMaterial->GetFName().ToString()));

    //auto mesh = Helpers::GetRootMeshComponent(this);

    ApplyMaterial(PrimaryMaterial);
    ////TArray<AActor*> AllChildren;
    ////GetAllChildActors(AllChildren);
    ////for (const auto& actor : AllChildren)
    ////{
    ////    const auto& item = Cast<AItemBase>(actor);
    ////    auto mesh = Cast<UStaticMeshComponent>(
    ////        item->GetComponentByClass(UStaticMeshComponent::StaticClass()));

    ////    //const auto& mesh = Cast<UStaticMeshComponent>(component);
    ////    UE_LOG(LogTemp, Display, TEXT("Tetris> Child:%s"),
    ////        *(mesh->GetFName().ToString()));
    ////    mesh->SetMaterial(0, PrimaryMaterial);
    ////}

    //auto mesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
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


// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Helpers.h"
#include "Elements/Framework/TypedElementHandle.h"

// Sets default values
AItemBase::AItemBase()
{
    // restore to activate the Tick and the debug info
    PrimaryActorTick.bCanEverTick = false;

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

// This function must be overridden
// but cannot be declarated as abstract
FMatrix44f AItemBase::GetShape(int Rotation)
{
    return FMatrix44f(
        FPlane4f(0, 0, 0, 0),
        FPlane4f(0, 1, 1, 0),
        FPlane4f(0, 0, 1, 0),
        FPlane4f(0, 0, 0, 0));
}

EShapeKind AItemBase::GetShapeKind()
{
    return EShapeKind::L;
}

bool AItemBase::GetLocationAndRotatorbyRotation(int Rotation, FVector* PreOffset, FRotator* Rotator, FVector* PostOffset)
{
    if (PreOffset == nullptr) return false;
    *PreOffset = FVector();
    *Rotator = FRotator();
    *PostOffset = FVector();
    return true;
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

void AItemBase::ShiftChildrenActors(FVector RelativeOffset)
{
    TArray<UChildActorComponent*> AllChildren;
    GetComponents<UChildActorComponent>(AllChildren);
    for (const auto& actorComponent : AllChildren)
    {
        auto child = Cast<AItemBase>(actorComponent->GetChildActor());
        child->SetActorRelativeLocation(RelativeOffset);
    }
}

void AItemBase::TetrisRotate(int Rotation)
{
}


bool AItemBase::Ungroup(AActor* NewParent, TArray<AActor*>& detachedActors)
{
    // GetComponentsByClass is obsolete and can be replaced as follows
    //auto AllChildren = GetComponentsByClass(UChildActorComponent::StaticClass());

    TArray<UChildActorComponent*> AllChildren;
    GetComponents<UChildActorComponent>(AllChildren);
    if (AllChildren.IsEmpty()) return false;

    auto world = GetWorld();
    for (const auto& actorComponent : AllChildren)
    {
        auto childActorComponent = Cast<UChildActorComponent>(actorComponent);
        auto child = Cast<AItemBase>(childActorComponent->GetChildActor());

        AItemBase* newChild = Helpers::CloneActor<AItemBase>(world, child);
        detachedActors.Push(newChild);
    }

    Destroy();
    return true;
}

void AItemBase::Rotate()
{
}

void AItemBase::SetTileStatus(EMaterialKind MaterialKind)
{
    UMaterialInterface* material = nullptr;
    if (MaterialKind == EMaterialKind::Primary)
        material = PrimaryMaterial;
    else if (MaterialKind == EMaterialKind::Secondary)
        material = SecondaryMaterial;

    UE_LOG(LogTemp, Display, TEXT("Tetris> AItemBase Primary material:%s"),
        *(material->GetFName().ToString()));

    ApplyMaterial(material);
}

// Called every frame only if bCanEverTick is true
void AItemBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector From = GetActorLocation();
    FVector To = From + FVector(0, 0, 200);

    DrawDebugDirectionalArrow(GetWorld(),
        From, To, 50, FColor::Magenta, false, -1, 0, 4);

}


// Fill out your copyright notice in the Description page of Project Settings.

#include "Piece.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include <vector>


//establece valores predeterminados 
APiece::APiece()
{

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SceneComponent = CreateDefaultSubobject<USceneComponent>("Pieces Scene");
    RootComponent = SceneComponent;
}

// Llamado cuando comienza el juego o cuando se genera
void APiece::BeginPlay()
{
    Super::BeginPlay();

}

// Se llama a cada fotograma
void APiece::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APiece::SpawnBlocks()
{
    std::vector<std::vector<std::pair<float, float>>> Shapes =     //se crea un vector de vectores de pares flotantes 
    {
        {{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {10.0, 0.0}},              // Pieza Linea H
        {{0.0, -20.0}, {0.0, -10.0}, {0.0, 0.0}, {0.0, 10.0}},              // Pieza Linea V
        {{0.0, 10.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}},                // Pieza L   
        {{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}},              // Pieza L invertida
        {{0.0, 0.0}, {10.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},             // Pieza Cuadrado
        {{-10.0, -10.0}, {0.0, -10.0}, {0.0, 0.0}, {10.0, 0.0}},            // Pieza Z invertida
        {{-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}},               // Pieza T invertida
        {{-10.0, 0.0}, {0.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},            // Pieza Z
        {{-10.0, 0.0}, {0.0, 0.0}, {10.0, 0.0}, {0.0, 10.0}, {0.0, -10.0}},  // Pieza Cruz
        //{{-20.0, 10.0}, {-10.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}}, ///bloques representa bloques individuales de una pieza 
    };
    Index = FMath::RandRange(0, Shapes.size() - 1); //genera la pieza aleatoria entre 0 y el tamaño del vector shepes -1
    UE_LOG(LogTemp, Warning, TEXT("index=%d"), Index);
    //se declara la variable YZs
    const std::vector<std::pair<float, float>>& YZs = Shapes[Index];//guarde la posicion en el vector (se guarda la pieza)
    //auto&& declara automaticamente la variable
    for (auto&& YZ : YZs)//crea y une bloque por bloque
    {
        FRotator Rotation(0.0, 0.0, 0.0);
        ABlock* B = GetWorld()->SpawnActor<ABlock>(this->GetActorLocation(), Rotation);
        //B->Mesh->SetMaterial(1, Colors[Index]);
        Blocks.Add(B);
        B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
        B->SetActorRelativeLocation(FVector(0.0, YZ.first, YZ.second));
    }
}




void APiece::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    UE_LOG(LogTemp, Warning, TEXT("Piezas eliminadas"));
}

void APiece::Dismiss()//elimina la pieza actual 
{
    Blocks.Empty();
}


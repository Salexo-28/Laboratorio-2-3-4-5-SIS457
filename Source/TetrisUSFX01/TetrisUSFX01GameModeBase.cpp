// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"
//
void ATetrisUSFX01GameModeBase::BeginPlay()
{
    //ciclo que genera bloques
    GetWorldTimerManager().SetTimer(Time_Controller, this, &ATetrisUSFX01GameModeBase::Spawn_Bloque, TIntervalo, true);

    Super::BeginPlay();


}
//funcion que genera los bloques
void ATetrisUSFX01GameModeBase::Spawn_Bloque()
{

    TInicial = TInicial + TIntervalo;
    if (TInicial < TMaximo)
    {
        positionZ = positionZ + 120;
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Orange , TEXT("Bloque generado"));
        FTransform SpawnLocation;

        SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
        SpawnedPiece->SetActorRelativeLocation(FVector(positionX, positionY, positionZ));
        SpawnedPiece->SpawnBlocks();
        SpawnedPiece->setPositionX(positionX);
        SpawnedPiece->setPositionY(positionY);
        SpawnedPiece->setPositionZ(positionZ);
            //guarda el nombre y posicion de la pieza
        mpcontenedor.Add(cont_map, SpawnedPiece);
        cont_map++;
    }
    else
    {
        GetWorldTimerManager().ClearTimer(Time_Controller);//cancela el temporizador
        GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Orange, TEXT("Tiempo Cumplido"));
        //muestra el Tmap
        for (int i = 0; i < cont_map; i++)
        {
            pos_vector = mpcontenedor[i]->GetIndex();
            //nombres y posicion de los objetos 
            switch (pos_vector) 
            {
            case 0:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza linea Horizontal con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 1:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza linea Vertical con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: " ) + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 2:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza L con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 3:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza L invertida con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 4:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Cuadrado con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 5:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Z invertida con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 6:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza T invertida con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 7:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Z con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
                break;
            case 8:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Cruz con posicion en x: ") + FString::FromInt(mpcontenedor[i]->getPositionX()) + TEXT(", en y: ") + FString::FromInt(mpcontenedor[i]->getPositionY()) + TEXT(", en z: ") + FString::FromInt(mpcontenedor[i]->getPositionZ()));
            }
        }
    }
}

void ATetrisUSFX01GameModeBase::DestroyActorFunction()
{
    if (SpawnedActor != nullptr)
    {
        // Displays a red message on the screen for 10 seconds
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Block destruido"));
        SpawnedActor->Destroy();
    }
}

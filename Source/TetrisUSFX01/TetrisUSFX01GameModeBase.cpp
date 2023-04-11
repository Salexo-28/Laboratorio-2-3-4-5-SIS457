// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"
//
void ATetrisUSFX01GameModeBase::BeginPlay()
{
    GetWorldTimerManager().SetTimer(Time_Controller, this, &ATetrisUSFX01GameModeBase::Spawn_Bloque, TIntervalo, true);

    Super::BeginPlay();


}
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
        mpcontenedor.Add(cont_map, SpawnedPiece);
        cont_map++;
    }
    else
    {
        GetWorldTimerManager().ClearTimer(Time_Controller);
        GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Orange, TEXT("Tiempo Cumplido"));
         for (int i = 0; i < cont_map; i++)
        {
            pos_vector = mpcontenedor[i]->GetIndex();
            switch (pos_vector) 
            {
            case 0:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza linea Horizontal - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 1:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza linea Vertical - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 2:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza L - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 3:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza L invertida - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 4:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Cuadrado - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 5:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Z - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 6:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza T - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 7:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Z - Numero de pieza: ") + FString::FromInt(i+1));
                break;
            case 8:
                GEngine->AddOnScreenDebugMessage(-1, 25, FColor::Yellow, TEXT("Pieza Cruz - Numero de pieza: ") + FString::FromInt(i+1));
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

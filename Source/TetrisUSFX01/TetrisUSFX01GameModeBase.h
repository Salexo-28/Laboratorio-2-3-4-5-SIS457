// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Block.h"
#include "Piece.h"
#include "TetrisUSFX01GameModeBase.generated.h"

UCLASS()
class TETRISUSFX01_API ATetrisUSFX01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	FTimerHandle Time_Controller;
	float positionX = 0.0; 
	float positionY = 0.0;
	float positionZ = 0.0;
	float TInicial = 0.0f;
	float TMaximo = 30.01f;
	float TIntervalo = 5.0f;
	int cont_map = 0;
	int pos_vector;
protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	ABlock* SpawnedActor;
	
	UPROPERTY()
	APiece* SpawnedPiece;

	UFUNCTION()
		void DestroyActorFunction();

	TMap<int, APiece*> mpcontenedor;
public:
	void Spawn_Bloque();
};

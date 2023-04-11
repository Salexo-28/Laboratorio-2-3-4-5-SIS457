// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Piece.h"
#include "Board.generated.h"

UCLASS() //
class TETRISUSFX01_API ABoard : public APawn //representa el tablero del juego contiene logica para manejar las piezas
{
	GENERATED_BODY()//genera el cuerpo de la clase

public:
	// inicializa valores predeterminados para las propiedades de clase
	ABoard();

protected:
	// Llama cuando comienza el juego o cuando se genera
	virtual void BeginPlay() override;

public:	
	// Se llama a cada fotograma 
	virtual void Tick(float DeltaTime) override;

	// Se llama para vincular la funcionalidad del controlador de entrada a la instancia el tablero 
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

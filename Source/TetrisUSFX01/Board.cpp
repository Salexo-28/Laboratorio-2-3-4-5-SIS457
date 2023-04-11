// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"

// Establece valores predeterminados
ABoard::ABoard()
{
 	// Establezca este peón para llamar a Tick() cada fotograma.  Puede desactivar esto para mejorar el rendimiento si no lo necesita.
	PrimaryActorTick.bCanEverTick = true;

}

// Llamado cuando comienza el juego o cuando se genera
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Se llama a cada fotograma
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Se llama para enlazar la funcionalidad a la entrada
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

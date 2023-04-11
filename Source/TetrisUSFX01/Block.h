/*la clase "ABlock" define un actor de bloque en Unreal Engine 4.
La clase tiene una propiedad de componente de malla estática y funciones virtuales para manejar la inicialización y actualización del actor.*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class TETRISUSFX01_API ABlock : public AActor
{
	GENERATED_BODY()

public:
	// Establece valores por defecto para las propiedades de este actor
	ABlock();

protected:
	// Llamado cuando el juego comienza o cuando se genera
	/*La función virtual "BeginPlay()" se define para manejar cualquier inicialización necesaria cuando el actor se crea y se inicializa.
	Esta función se llama después del constructor de la clase y antes de la función "Tick()".*/
	virtual void BeginPlay() override;

public:
	// Llamada en cada fotograma
	/*La función virtual "Tick()" se define para manejar cualquier actualización necesaria en el actor mientras está activo en el mundo del juego.
	Esta función se llama una vez por fotograma y recibe como argumento el tiempo transcurrido desde el fotograma anterior.*/
	virtual void Tick(float DeltaTime) override;


	/* El modificador "EditAnywhere" se utiliza para permitir que la propiedad sea modificada en el editor de Unreal Engine 4.
	La propiedad "BlockMesh" es un componente de malla estática que se utiliza para visualizar el bloque en el mundo del juego.
	Esta propiedad se define como un puntero a un objeto de la clase "UStaticMeshComponent".*/
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BlockMesh;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.h"
#include "Piece.generated.h"
//AActor es una clase base para todos los objetos 
// la clase APIece representa una pieza 
UCLASS()
class TETRISUSFX01_API APiece : public AActor //llamando a la clase actor de la biblioteca de unreal  
{
	GENERATED_BODY()
private:
	//variables de nombre y posicion
	float positionX;
	float positionY;
	float positionZ; //crea la posicion 
	int Index; //identifica una pieza, se establece y se obtiene con los metodos set(), get() 
	//indice 
public:
	// constructor de la clase
	APiece();

protected:
	// llama cuando el programa inicia
	virtual void BeginPlay() override;//agrega un objeto 
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override; //elimina un objeto
	//son heredados de la clase AActor 
public:
	//Se llama a cada fotograma
	virtual void Tick(float DeltaTime) override;// llama una vez por fotograma para actualizar el estado del objeto 
	//heredado de la clase Actor
	//DeltaTime actualica la picision en funcion del tiempo
	UPROPERTY()//?
		class USceneComponent* SceneComponent;

	void Dismiss(); //borra la pieza 

private:
	//vector de punteros a bloques
	TArray<ABlock*> Blocks; //es una matriz de punteros a objetos (contenedor) se usa para guardar los bloques que componen la pieza

public:
	void SpawnBlocks(); // metodo para manipular la pieza 
	//setter y getter para la posicion
	void setPositionX(float _positionX) { positionX = _positionX; }
	void setPositionY(float _positionY) { positionY = _positionY; }
	void setPositionZ(float _positionZ) { positionZ = _positionZ; }
	int GetIndex() const { return Index; }//obtiene la posicion de la pieza y devuelve el valor actual de la variable 
	float getPositionX() { return positionX; }
	float getPositionY() { return positionY; }
	float getPositionZ() { return positionZ; }

};

#include "Block.h"
/* Esta clase crea un objeto de bloque en el mundo del juego que se puede actualizar y mostrar en la pantalla
y define metodos que se llaman en diferentes momentos durante la ejecucion del juego.*/

// Establece valores por defecto
ABlock::ABlock()
{
	/* En este constructor, se desactiva la actualizacion del actor si no se necesita.
	Esto se hace a traves de la propiedad "bCanEverTick" de la estructura "FTickFunction", que es una propiedad de "PrimaryActorTick".
	Esta propiedad determina si el actor puede ser actualizado o no.
	Si se establece en "false", el actor no se actualizara y mejorara el rendimiento del juego. */

	PrimaryActorTick.bCanEverTick = true;

	/* Luego, se crea un componente de malla estÃ¡tica "BlockMesh" utilizando el metodo "CreateDefaultSubobject".
	El componente de malla se utiliza para visualizar el bloque en el mundo del juego.
	La propiedad "RootComponent" se establece en "BlockMesh" para indicar que este componente es el componente principal del actor. */

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	RootComponent = BlockMesh;

	// se carga una malla estatica desde un archivo utilizando el "ConstructorHelpers::FObjectFinder" que busca un objeto en el contenido del proyecto.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	//Genera el tamano del bloque, busca la posicion del asset
	/* Si se encuentra la malla estatica, se establece en el componente de malla "BlockMesh" utilizando el metodo "SetStaticMesh".
	Ademas, se establece la ubicacion y escala de la malla utilizando "SetRelativeLocation" y "SetWorldScale3D" respectivamente.*/
	if (BlockMeshAsset.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockMeshAsset.Object);
		BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		BlockMesh->SetWorldScale3D(FVector(0.1f, 0.1f, 0.1f));

		//AActor* MyActor = ...; // Obtener el puntero al actor que se desea modificar
		//FVector NewScale(2.0f, 2.0f, 2.0f); // Crear un vector que representa la nueva escala
		//ChangeActorSize(MyActor, NewScale); // Llamar a la funcion para cambiar el tamano del actor

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
		//Si la malla no se encuentra, se muestra un mensaje de advertencia en el registro de Unreal Engine 4.
	}
}

// Llamado cuando el juego comienza o cuando se genera.
/* Es un metodo virtual en la clase "AActor" que se llama cuando el actor se agrega
al mundo del juego y se inicializa.*/
void ABlock::BeginPlay()
{
	Super::BeginPlay();

}

// Llamada en cada fotograma
//Es un metodo virtual en "AActor" que se llama en cada fotograma del juego.
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



// Fill out your copyright notice in the Description page of Project Settings.


#include "TNFieldBase.h"
#include "Tenetris/Module/MVC/View/Field/Actor/Mino/TNMinoBase.h"
#include "Tenetris/Module/MVC/View/Field/Actor/Components/TenetrisBufferComponent/TNTenetrisBufferComponent.h"

// Sets default values
ATNFieldBase::ATNFieldBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT_COMPONENT"));

	TenetrisBufferComponent = CreateDefaultSubobject<UTNTenetrisBufferComponent>(TEXT("BufferComponent"));
	TenetrisBufferComponent->SetBufferSize(RowMax, ColumnMax);
	TenetrisBufferComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TenetrisBufferComponent->SetMobility(EComponentMobility::Movable);

	// SetActorTickInterval(1.f);
	MinoClass = ATNMinoBase::StaticClass();
}

ATNFieldBase::~ATNFieldBase()
{

}

// Called when the game starts or when spawned
void ATNFieldBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATNFieldBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATNFieldBase::Initialize()
{
	if (IsValid(TenetrisBufferComponent))
	{
		TenetrisBufferComponent->Initialize();
	}
}

void ATNFieldBase::SetMinoClassType(TSubclassOf<ATNMinoBase> minoClass)
{
	if (IsValid(TenetrisBufferComponent))
	{
		TenetrisBufferComponent->SetMinoClassType(minoClass);
	}
}

void ATNFieldBase::SetBackgroundCubeType(int32 x, int32 y, E_TNTetrominoType tetrominoType)
{
	setBackgroundCubeType(x, y, tetrominoType);
}

void ATNFieldBase::SetMinoType(const int32 x, const int32 y, const E_TNTetrominoType tetrominoType)
{
	if (IsValid(TenetrisBufferComponent))
	{
		TenetrisBufferComponent->SetMinoType(x, y, tetrominoType);
	}
}

void ATNFieldBase::SetVisibilityMino(const int32 x, const int32 y, const bool visible)
{
	if (IsValid(TenetrisBufferComponent))
	{
		TenetrisBufferComponent->SetVisibilityMino(x, y, visible);
	}
}

void ATNFieldBase::SetVisibilityBackgroundCube(const int32 x, const int32 y, const bool visible)
{
	if (IsValid(TenetrisBufferComponent))
	{
		TenetrisBufferComponent->SetVisibilityBackgroundCube(x, y, visible);
	}
}

void ATNFieldBase::setBackgroundCubeType(int32 x, int32 y, E_TNTetrominoType tetrominoType)
{
	if (IsValid(TenetrisBufferComponent))
	{
		TenetrisBufferComponent->SetBackgroundCubeType(x, y, tetrominoType);
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tenetris/TenetrisDefine.h"

class FTNTetrominoGenerator
{
public:
	FTNTetrominoGenerator()
		: TetrominoArrayResetCounter(0)
	{}

	~FTNTetrominoGenerator() {}

	void Initialize();

	E_TNTetrominoType GetTop();
	E_TNTetrominoType GetAt(const int32 index);

private:
	void shuffleTetrominoBag(TArray<E_TNTetrominoType>& bag);
	void refillTetrominoArray(const int32 tetrominoArrayResetCounter);

private:
	TArray<E_TNTetrominoType> TetrominoArray;
	int32 TetrominoLimitCounter;
	int32 TetrominoArrayResetCounter;
};
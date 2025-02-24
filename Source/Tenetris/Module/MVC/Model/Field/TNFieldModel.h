#include "Tenetris/TenetrisDefine.h"

class ATNField;
class FTNTetrominoBase;
class FTNPlayerTetromino;
class FTNTetrominoGenerator;

DECLARE_DELEGATE_TwoParams(FTNUpdateModel, const int32, const E_TNFieldModelStateType);

class FTNFieldModel
{
public:
	FTNFieldModel(FTNFieldContext fieldContext);
	virtual ~FTNFieldModel() {}

public:
	void Initialize();
	void SetId(const int32 id);
	int32 GetId();
	void Tick(float deltaTime);
	void SetBufferSize(const int32 bufferHeight, const int32 bufferWidth);
	E_TNTetrominoType GetValueFromCheckBuffer(const int32 x, const int32 y) const;
	void SetValueToCheckBuffer(const int32 x, const int32 y, const E_TNTetrominoType tetrominoType);
	bool CheckMino(const int32 x, const int32 y);
	int32 CalculateGuideMinoHeight(const int32 x, const int32 y);
	void HidePreviewTetromino();
	void SetPreviewTetromino();
	void HideHoldTetromino();
	void SetHoldTetromino();
	void HideTetromino();
	void SetTetromino();
	void HideGuideTetromino();
	void SetGuideTetromino();
	void CheckLineDelete(const TArray<int32>& heights);
	bool IsLineDeleted(int32 height) const;
	void HandleLineDeletion(const TArray<int32>& linesToDelete);
	TArray<TArray<E_TNTetrominoType>>& GetCheckBuffer();

	FTNFieldContext& GetFieldContext() {
		return FieldContext;
	}

	virtual FTNUpdateModel& GetOnUpdateModelDelegate() {
		return OnUpdateModel;
	}

	TSharedPtr<FTNPlayerTetromino> GetCurrentTetromino()
	{
		return CurrentTetromino;
	}
	
	TSharedPtr<FTNTetrominoBase> GetHoldTetromino()
	{
		return HoldTetromino;
	}

	TArray<TSharedPtr<FTNTetrominoBase>>& GetPreviewTetrominos()
	{
		return PreviewTetrominos;
	}

	void StartMoveLeft();
	void StopMoveLeft();

	void StartMoveRight();
	void StopMoveRight();

	void StartSoftDrop();
	void StopSoftDrop();

	void RotateClockWise();
	void RotateCounterClockWise();

	void Hold();
	void ToggleSpaceInversion();
	void HardDrop();

public:
	void AddFieldActor(ATNField* fieldActor);

private:
	void initializePreviewTetrominos();
	void initializeHoldTetromino();

	void spawn();

	bool moveTetromino(E_TNTetrominoDirection tetrominoDirection);
	void rotateTetromino(E_TNTetrominoRotation tetrominoRotation);
	void setMoveDirection(E_TNTetrominoDirection tetrominoDirection, bool pressed);
	void setSoftDrop(bool softDrop) { bSoftDrop = softDrop; }
	bool getSoftDrop() { return bSoftDrop; }

	void tetrominoFall(float deltaTime);
	void setMoveState(float deltaTime, FTNMoveDirectionState& moveState, E_TNTetrominoDirection tetrominoDirction);
	void updateLockDown(float deltaTime);
	void updateLineDelete(float deltaTime);

	void lineDelete();
	void doLockDown();
	void waitForSpawn();

	void spawnNextTetromino();
	void renewPreviewTetromino();
	float getFallingSpeed();
	

private:

	FTNFieldContext FieldContext;
	ATNField* FieldActor;

	TSharedPtr<FTNPlayerTetromino> CurrentTetromino;
	TSharedPtr<FTNTetrominoGenerator> TetrominoGenerator;
	TArray<TSharedPtr<FTNTetrominoBase>> PreviewTetrominos;

	TArray<int32> DeletedLines;
	float DeleteLineCheckTime = 0.f;
	bool bLineDeleting = false;
	bool bSpaceInverted = false;

	float TetrominoFallingSpeed = 1.f;
	float CurrentTime = 0.f;

	TSharedPtr<FTNTetrominoBase> HoldTetromino;

	FTNUpdateModel OnUpdateModel;

private:
	int32 Id = 0;
	bool bSoftDrop = false;
	FTNMoveDirectionState LeftDirectionState;
	FTNMoveDirectionState RightDirectionState;
	E_TNTetrominoDirection TetrominoMoveDirection = E_TNTetrominoDirection::None;
	float KickInDelay = 0.3f;
	float MoveSpeed = 0.05f;
	FTNLockDown LockDown;
	bool bWaitForSpawn = false;
	bool bCanHold = true;
};
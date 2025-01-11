// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DefaultItem.h"
#include "DefaultEnemy.h"
#include "BaseQuest.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EQuestReward : uint8
{
	E_Default		UMETA(DisplayName = "DEFAULT"),
	E_Experience    UMETA(DisplayName = "EXPERIENCE"),
	E_Item			UMETA(DisplayName = "ITEM")
};

UENUM(BlueprintType)
enum class EClearCondition : uint8
{
	E_Default		UMETA(DisplayName = "DEFAULT"),
	E_Slay		    UMETA(DisplayName = "SLAY"),
	E_Collect		UMETA(DisplayName = "COLLECT"),
	E_Travel		UMETA(DisplayName = "TRAVEL")
};
USTRUCT(BlueprintType)
struct FReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestReward rewardType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ADefaultItem> item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float experience;

};

USTRUCT(BlueprintType)
struct FObjective
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EClearCondition clearType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ADefaultEnemy> enemyToSlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf <ADefaultItem> itemToCollect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ObjectiveID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int numRequired;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsComplete;
	
};
UCLASS(BlueprintType)
class QUESTSYSTEM_API UBaseQuest : public UObject
{
	GENERATED_BODY()

	UBaseQuest();

public:
	
	UFUNCTION(BlueprintCallable)
	void SetQuestDetails(FString _name, FString _description);
	
	UFUNCTION(BlueprintCallable)
	void SetUpObjective(int _objectiveNum, TSubclassOf<ADefaultEnemy> _enemy, TSubclassOf <ADefaultItem> _item, FString _description1, FString _description2, int _numRequired);

	UFUNCTION(BlueprintCallable)
	void SetNumObjectives(int _numeObjectives);

	UFUNCTION(BlueprintCallable)
	void UpdateQuest();

	UFUNCTION(BlueprintCallable)
	void UpdateObjective(int _objectiveNum, int _updateValue);

	UFUNCTION(BlueprintCallable)
	void FinishObjective(int _objectiveNum);

	UFUNCTION(BlueprintCallable)
	void FinishQuest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FReward reward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObjective> objectives;
	
};

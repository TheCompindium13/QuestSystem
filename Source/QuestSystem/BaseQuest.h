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
	ADefaultEnemy* enemyToSlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ADefaultItem* itemToCollect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int numRequired;
	
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
	void SetUpObjective(int _objectiveNum, ADefaultEnemy* _enemy, ADefaultItem* _item, FString _description, int _numRequired);

	UFUNCTION(BlueprintCallable)
	void SetNumObjectives(int _numeObjectives);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FReward reward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObjective> objectives;
	
};

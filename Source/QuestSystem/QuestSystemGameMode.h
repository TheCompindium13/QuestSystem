// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "QuestSystemGameMode.generated.h"

UCLASS(minimalapi)
class AQuestSystemGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AQuestSystemGameMode();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateObjectiveHUD(int _objectiveNum);
	UFUNCTION(BlueprintImplementableEvent)
	void HideObjective(int _objectiveNum);
	UFUNCTION(BlueprintImplementableEvent)
	void HideQuest();
};




// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseQuest.h"

UBaseQuest::UBaseQuest()
{
	// Set the default values for variables 
	name = "Default Quest";
	description = "Description Needed.";

	reward.rewardType = EQuestReward::E_Default;
	reward.experience = 100.0f;
	reward.item = nullptr;
}

void UBaseQuest::SetQuestDetails(FString _name, FString _description)
{
	name = _name;
	description = _description;
}

void UBaseQuest::SetUpObjective(int _objectiveNum, ADefaultEnemy* _enemy, ADefaultItem* _item, FString _description, int _numRequired)
{
	if (_objectiveNum < objectives.Num())
	{
		if (_enemy != nullptr)
		{
			objectives[_objectiveNum].clearType = EClearCondition::E_Slay;
			objectives[_objectiveNum].enemyToSlay = _enemy;
		}
		else if (_item != nullptr)
		{
			objectives[_objectiveNum].clearType = EClearCondition::E_Collect;
			objectives[_objectiveNum].itemToCollect = _item;
		}
		objectives[_objectiveNum].description = _description;
		objectives[_objectiveNum].numRequired = _numRequired;
	}
}

void UBaseQuest::SetNumObjectives(int _numObjectives)
{
	objectives.SetNum(_numObjectives)
}

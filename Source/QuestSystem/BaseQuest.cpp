// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseQuest.h"
#include "QuestSystemGameMode.h"
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

void UBaseQuest::SetUpObjective(int _objectiveNum, TSubclassOf<ADefaultEnemy> _enemy, TSubclassOf <ADefaultItem> _item, FString _description1, FString _description2, int _numRequired)
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
		objectives[_objectiveNum].ObjectiveID = _objectiveNum;
		objectives[_objectiveNum].numRequired = _numRequired;

		//Create the complete description of the objective.
		objectives[_objectiveNum].description.Append(_description1 + "<NR>");
		objectives[_objectiveNum].description.AppendInt(_numRequired);
		objectives[_objectiveNum].description.Append("<NR> " + _description2);
	}
}

void UBaseQuest::SetNumObjectives(int _numObjectives)
{
	objectives.SetNum(_numObjectives) ; 
}

void UBaseQuest::UpdateQuest()
{
}
void UBaseQuest::UpdateObjectiveDescription(FString& _description, int _numRequired)
{
	FString firstString;
	FString secondString;
	FString updatedNum;
	updatedNum.AppendInt(_numRequired);

	_description.Split("<NR>", &firstString, &secondString);
	secondString = secondString.Replace(*secondString.Left(secondString.Find("<NR>")), *updatedNum);
	_description.Append("<NR>").Append(secondString);
	

}
void UBaseQuest::UpdateObjective(int _objectiveNum, int _updateValue)
{
	if (_objectiveNum < objectives.Num())
	{
		objectives[_objectiveNum].numRequired -= _updateValue;

		UE_LOG(LogTemp, Warning, TEXT("You Need To Perform That Action %d More Times."), objectives[_objectiveNum].numRequired);

		if (objectives[_objectiveNum].numRequired <= 0)
		{
			FinishObjective(_objectiveNum);
		}
	}
}

void UBaseQuest::FinishObjective(int _objectiveNum)
{
	if (_objectiveNum < objectives.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("You have Completed Objective %d"),_objectiveNum);
		objectives[_objectiveNum].IsComplete = true;

		if (AQuestSystemGameMode *gameModeRef = Cast<AQuestSystemGameMode>(GetOuter()))
		{
			gameModeRef->HideObjective(_objectiveNum);
		}
		int numFinished = 0;
		for (int i = 0; i < objectives.Num(); ++i)
		{
			if (objectives[i].IsComplete)
			{
				++numFinished;
			}
		}

		if (numFinished >= objectives.Num())
		{
			FinishQuest();
		}
	}
}

void UBaseQuest::FinishQuest()
{
	UE_LOG(LogTemp, Warning, TEXT("You Have completed Quest: %d."), *name);

	if (AQuestSystemGameMode *gameModeRef = Cast<AQuestSystemGameMode>(GetOuter()))
	{
		gameModeRef->HideQuest();
	}
}

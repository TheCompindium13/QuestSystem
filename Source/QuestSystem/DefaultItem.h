// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefaultItem.generated.h"

UCLASS()
class QUESTSYSTEM_API ADefaultItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefaultItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//The Weight of The Item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float weight;

	//The Name of The Item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void NotifyCollected();


public:	


};

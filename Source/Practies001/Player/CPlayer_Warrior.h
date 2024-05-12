// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/CPlayer.h"
#include "CPlayer_Warrior.generated.h"

/**
 * 
 */
UCLASS()
class PRACTIES001_API ACPlayer_Warrior : public ACPlayer
{
	GENERATED_BODY()
public:

public:
	EJob Job = EJob::Warrior;
	
};

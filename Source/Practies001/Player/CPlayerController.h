// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PRACTIES001_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ACPlayerController();

protected:
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

private:
	void SetNewDestination(const FVector Destination);

	void MoveToMouseCursor();

	void InputRightMouseButtonPressed();
	void InputRightMouseButtonReleased();

private:
	bool bClickRightMouse;

};

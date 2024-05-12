// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/CStateComponent.h"
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
	virtual void BeginPlay() override;
protected:
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

public:

	void GetHitResult(FHitResult hitResult);

private:
	void SetNewDestination(const FVector Destination);

	void MoveToMouseCursor();

	void InputRightMouseButtonPressed();
	void InputRightMouseButtonReleased();
	void InputSpacebarButtonPressed();
	void InputLeftMouseButtonPressed();

public:
	UFUNCTION(BlueprintNativeEvent)
	void ChangeFisrt();
	void ChangeFisrt_Implementation();
	UFUNCTION(BlueprintNativeEvent)
	void ChangeSecond();
	void ChangeSecond_Implementation();
	
	UFUNCTION(BlueprintNativeEvent)
	void ChangeThird();
	void ChangeThird_Implementation();

		UFUNCTION(BlueprintNativeEvent)
	void ddd();
	void ddd_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void ffff(AActor* InActor, AActor* OutActor);
	void ffff_Implementation(AActor* InActor, AActor* OutActor);

private:
	bool bClickRightMouse;
	FHitResult HitResult;
	APawn* CurrentPawn;

public:
	
	UPROPERTY(BlueprintReadOnly)
		TSubclassOf<class ACPlayer> PlayerClass;

};

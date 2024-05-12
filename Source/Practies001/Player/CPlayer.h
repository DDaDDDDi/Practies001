#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CStateComponent.h"
#include "CPlayer.generated.h"


UCLASS()
class PRACTIES001_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	void OnEvade();

public:
	UFUNCTION(BlueprintNativeEvent)
		void First(APawn* InPawn);
	void First_Implementation(APawn* InPawn);

	UFUNCTION(BlueprintNativeEvent)
		void DoAction();
	void DoAction_Implementation();

private:
	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

	void Begin_Roll();
	void End_Roll();

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE FName GetTagname() { return TagName; }
	UFUNCTION(BlueprintPure)
		FORCEINLINE EJob GetJob() { return Job; }

private:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = true))
		class UCameraComponent* CameraComp;
		
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = true))
		class USpringArmComponent* SpringArmComp;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;

	UPROPERTY(EditAnywhere)
	float ArmLength = 1200.f;
	
public:

	UPROPERTY(BlueprintReadWrite)
		EJob Job = EJob::Max;
private:
	FName TagName;
};

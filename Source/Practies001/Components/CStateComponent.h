#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"

UENUM(BlueprintType)
enum class EStateType : uint8
{
	Idle, Roll,Hitted , Dead, Max
};

UENUM(BlueprintType)
enum class EJob : uint8
{
	Knight, Warrior, Archer, magician, Max
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateTypeChangedSignature, EStateType, InPrevType, EStateType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRACTIES001_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStateComponent();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsIdleMode() { return Type == EStateType::Idle; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsRollMode() { return Type == EStateType::Roll; }
	
public:
	void SetIdleMode();
	void SetRollMode();

private:
	void ChangeType(EStateType InNewType);

public:
	FORCEINLINE EStateType GetType() { return Type; }
	FORCEINLINE EStateType GetPrevType() { return PrevType; }


public:
	UPROPERTY(BlueprintAssignable)
		FStateTypeChangedSignature OnStateTypeChanged;


private:
	EStateType Type;
	EStateType PrevType;
};

#include "CStateComponent.h"

UCStateComponent::UCStateComponent()
{

}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCStateComponent::SetIdleMode()
{
	ChangeType(EStateType::Idle);
}

void UCStateComponent::SetRollMode()
{
	ChangeType(EStateType::Roll);
}

void UCStateComponent::ChangeType(EStateType InNewType)
{
	PrevType = Type;
	Type = InNewType;

	if (OnStateTypeChanged.IsBound())
		OnStateTypeChanged.Broadcast(PrevType, InNewType);
}
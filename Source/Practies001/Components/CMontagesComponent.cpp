#include "CMontagesComponent.h"
#include "GameFramework/Character.h"

UCMontagesComponent::UCMontagesComponent()
{
}


void UCMontagesComponent::BeginPlay()
{
	Super::BeginPlay();

	if (DataTable == nullptr)
	{
		return;
	}

	TArray<FMontageData*> datas;
	DataTable->GetAllRows<FMontageData>("", datas);

	for (int32 i = 0; i < (int32)EStateType::Max; i++)
	{
		for (FMontageData* data : datas)
		{
			if (data->Type == (EStateType)i)
			{
				Datas[i] = data;
				break;
			}
		}
	}

}

void UCMontagesComponent::PlayRoll()
{
	PlayAnimMontage(EStateType::Roll);
}

void UCMontagesComponent::PlayAnimMontage(EStateType InStateType)
{
	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());
	if(ownerCharacter== nullptr)return;

	FMontageData* data = Datas[(int32)InStateType];

	if (!!data && !!data->AnimMontage)
	{
		ownerCharacter->PlayAnimMontage(data->AnimMontage, data->PlayRate, data->StartSection);
	}
}




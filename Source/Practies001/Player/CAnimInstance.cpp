#include "CAnimInstance.h"
#include "GameFramework/Character.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	ACharacter* ownerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if(ownerCharacter == nullptr)return;





}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* ownerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if(ownerCharacter== nullptr)return;

	Speed = ownerCharacter->GetVelocity().Size2D();

	FRotator controlRotation = FRotator(0, ownerCharacter->GetControlRotation().Yaw, 0);
	Direction = CalculateDirection(ownerCharacter->GetVelocity(), controlRotation);


}


#include "CPlayerController.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include "CPlayer.h"

ACPlayerController::ACPlayerController()
{
	bShowMouseCursor = true;

}

void ACPlayerController::BeginPlay()
{

}

void ACPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("RightClick", IE_Pressed, this, &ACPlayerController::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", IE_Released, this, &ACPlayerController::InputRightMouseButtonReleased);
	InputComponent->BindAction("Evade", IE_Pressed, this, &ACPlayerController::InputSpacebarButtonPressed);
}

void ACPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bClickRightMouse)
	{
		MoveToMouseCursor();
	}
	
}



void ACPlayerController::GetHitResult(FHitResult hitResult)
{
	hitResult = HitResult;
}

void ACPlayerController::SetNewDestination(const FVector Destination)
{
	APawn* const myPawn = GetPawn();

	if (myPawn)
	{
		float const distance = FVector::Dist(Destination, myPawn->GetActorLocation());
		if (distance > 120.f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination);
		}
	}
}

void ACPlayerController::MoveToMouseCursor()
{
	HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		SetNewDestination(HitResult.ImpactPoint); 
	}
}

void ACPlayerController::InputRightMouseButtonPressed()
{
	bClickRightMouse = true;
}

void ACPlayerController::InputRightMouseButtonReleased()
{
	bClickRightMouse = false;
}

void ACPlayerController::InputSpacebarButtonPressed()
{
	FHitResult hitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, hitResult);
	ACPlayer* playerC = Cast<ACPlayer>(GetCharacter());
	

}

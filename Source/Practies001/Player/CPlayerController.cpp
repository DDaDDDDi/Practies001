#include "CPlayerController.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>

ACPlayerController::ACPlayerController()
{
	bShowMouseCursor = true;

}

void ACPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("RightClick", IE_Pressed, this, &ACPlayerController::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", IE_Released, this, &ACPlayerController::InputRightMouseButtonReleased);
}

void ACPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bClickRightMouse)
	{
		MoveToMouseCursor();
	}
	
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
	FHitResult hitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, hitResult);

	if (hitResult.bBlockingHit)
	{
		SetNewDestination(hitResult.ImpactPoint); 
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

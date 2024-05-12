#include "CPlayerController.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include "CPlayer.h"
#include "CPlayer_Warrior.h"
#include "Global.h"

ACPlayerController::ACPlayerController()
{
	bShowMouseCursor = true;

	CHelpers::GetClass<ACPlayer>(&PlayerClass, "Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'");
	CheckNull(PlayerClass);

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
	InputComponent->BindAction("FisrtCharacter", IE_Pressed, this, &ACPlayerController::ChangeFisrt);
	InputComponent->BindAction("SecondCharacter", IE_Pressed, this, &ACPlayerController::ChangeSecond);
	InputComponent->BindAction("ThirdCharacter", IE_Pressed, this, &ACPlayerController::ChangeThird);
	InputComponent->BindAction("dddd", IE_Pressed, this, &ACPlayerController::ddd);

	InputComponent->BindAction("LeftCllick", IE_Pressed, this, &ACPlayerController::InputLeftMouseButtonPressed);
	
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
	CLog::Print("dddd");
	ACPlayer* player = Cast<ACPlayer>(GetPawn());
	CheckNull(player);
	player->OnEvade();

}

void ACPlayerController::InputLeftMouseButtonPressed()
{
	ACPlayer* player = Cast<ACPlayer>(GetPawn());
	CheckNull(player);
	player->DoAction();
}

void ACPlayerController::ChangeFisrt_Implementation()
{
	CLog::Print("dd");
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerClass, actors);

	ACPlayer_Warrior* playerC = Cast<ACPlayer_Warrior>(actors.Last());
	CheckNull(playerC);
	CLog::Print(playerC->GetName());
	
	if (playerC->Job == EJob::Warrior)
	{
		playerC->First(playerC);
	SetPawn(playerC);
	}
}

void ACPlayerController::ChangeSecond_Implementation()
{
}

void ACPlayerController::ChangeThird_Implementation()
{
}

void ACPlayerController::ddd_Implementation()
{
}

void ACPlayerController::ffff_Implementation(AActor* InActor, AActor* OutActor)
{
}

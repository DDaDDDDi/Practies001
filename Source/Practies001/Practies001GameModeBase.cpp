#include "Practies001GameModeBase.h"

APracties001GameModeBase::APracties001GameModeBase()
{
static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'"));
DefaultPawnClass = PlayerPawnClassFinder.Class;
static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassFinder(TEXT("Blueprint'/Game/Player/BP_CPlayerController.BP_CPlayerController_C'"));
PlayerControllerClass = PlayerControllerClassFinder.Class;

}
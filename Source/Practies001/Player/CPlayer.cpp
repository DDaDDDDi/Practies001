#include "CPlayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/CMontagesComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Global.h"


ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArmComp->SetupAttachment(GetMesh());
	SpringArmComp->SetUsingAbsoluteRotation(true);
	SpringArmComp->TargetArmLength = ArmLength;
	SpringArmComp->SetRelativeRotation(FRotator(-60.f, 45.f, 0.f));
	SpringArmComp->bDoCollisionTest = false;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	//static void CreateActorComponent(AActor * InActor, T * *OutComponent, FName InName)
	//{
	//	*OutComponent = InActor->CreateDefaultSubobject<T>(InName);
	//}	CHelpers::CreateActorComponent(this, &Action, "Action");

	Montages = CreateDefaultSubobject<UCMontagesComponent>("Montages");
	CHelpers::CreateActorComponent(this, &State, "State");
	

	USkeletalMesh* meshAsset;
	CHelpers::GetAsset<USkeletalMesh>(&meshAsset, "SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'");
	GetMesh()->SetSkeletalMesh(meshAsset);

	TSubclassOf<UAnimInstance> animInstanceClass;
	CHelpers::GetClass<UAnimInstance>(&animInstanceClass, "AnimBlueprint'/Game/Player/ABP_CPlayer.ABP_CPlayer_C'");
	GetMesh()->SetAnimInstanceClass(animInstanceClass);
	
	
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	State->OnStateTypeChanged.AddDynamic(this, &ACPlayer::OnStateTypeChanged);
	TagName = "1111";
	CameraComp->ComponentTags.Add(TagName);

}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPlayer::OnEvade()
{
	CheckFalse(State->IsIdleMode());
	//CheckFalse(Status->IsCanMove());

	State->SetRollMode();
}



void ACPlayer::First_Implementation(APawn* InPawn)
{
	UGameplayStatics::GetPlayerController(GetWorld(),0)->Possess(InPawn);
}

void ACPlayer::DoAction_Implementation()
{
	
}

void ACPlayer::OnStateTypeChanged(EStateType InPrevType, EStateType InNewType)
{

	switch (InNewType)
	{
	case EStateType::Roll:		Begin_Roll();		break;
//	case EStateType::Hitted:	Hitted(InPrevType);			break;
//	case EStateType::Dead:		Dead();			break;
	}
}

void ACPlayer::Begin_Roll()
{
	FVector start = GetActorLocation();
	FHitResult hit;
	FVector target;
	
	if (GetVelocity().IsNearlyZero())
	{
		target = start + hit.ImpactNormal;
	}
	else
	{
		target = start + hit.ImpactNormal;
	}


	Montages->PlayRoll();
}

void ACPlayer::End_Roll()
{
	State->SetIdleMode();
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "player2.h"
#include "MainCharacter.h"
#include "MyHUD.h"

// Sets default values
Aplayer2::Aplayer2(const FObjectInitializer& ObjectInitializer)
	: Super (ObjectInitializer)
{

	ProxSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("Proximity Sphere"));
	ProxSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	ProxSphere->SetSphereRadius(32.0f);
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &Aplayer2::Prox);
	NpcMessage = "editable message";
}

int Aplayer2::Prox_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if (Cast<AMainCharacter>(OtherActor) == nullptr) {
			
		return -1;
	}

	APlayerController* PController = GetWorld()->GetFirstPlayerController();

	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(Message(NpcMessage, 5.f, FColor::White));
	}
	return 0;
}





// Called when the game starts or when spawned
void Aplayer2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aplayer2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Aplayer2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


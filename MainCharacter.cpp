// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("ForwardMove", this, &AMainCharacter::ForwardMoveFunction);
	PlayerInputComponent->BindAxis("RightMove", this, &AMainCharacter::RightMoveFunction);
	PlayerInputComponent->BindAxis("LeftMove", this, &AMainCharacter::LeftMoveFunction);
	PlayerInputComponent->BindAxis("BackMove", this, &AMainCharacter::BackMoveFunction);
	PlayerInputComponent->BindAxis("Yaw", this, &AMainCharacter::Yaw);
	PlayerInputComponent->BindAxis("Pitch", this, &AMainCharacter::Pitch);
}

void AMainCharacter::ForwardMoveFunction(float amount)
{
	if (Controller && amount)
	{
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, amount);
	}

}

void AMainCharacter::RightMoveFunction(float amount)
{

	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}

}

void AMainCharacter::LeftMoveFunction(float amount)
{

	if (Controller && amount)
	{
		FVector left = - GetActorRightVector();
		AddMovementInput(left, amount);
	}
}

void AMainCharacter::BackMoveFunction(float amount)
{

	if (Controller && amount)
	{
		FVector back = - GetActorForwardVector();
		AddMovementInput(back, amount);
	}
}

void AMainCharacter::Yaw(float amount)
{
	AddControllerYawInput(60.f * amount * GetWorld()->GetDeltaSeconds());
}

void AMainCharacter::Pitch(float amount)
{
	AddControllerPitchInput(20.f * amount * GetWorld()->GetDeltaSeconds());
}


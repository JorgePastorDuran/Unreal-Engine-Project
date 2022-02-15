// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "player2.generated.h"

UCLASS()
class PERSONALPROYECT_API Aplayer2 : public ACharacter
{
	GENERATED_BODY()


public:

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
			USphereComponent* ProxSphere;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
			FString NpcMessage;


		UFUNCTION(BlueprintNativeEvent, Category = "Collision")
			void Prox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
				int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

		virtual int Prox_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	// Sets default values for this character's properties
	Aplayer2(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

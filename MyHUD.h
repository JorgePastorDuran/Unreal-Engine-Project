// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "MainCharacter.h"
#include "MyHUD.generated.h"


struct Message
{
	FString message;
	float time;
	FColor color;


	Message() {

		time = 5.f;
		color = FColor::White;
	}

	Message(FString iMessage, float iTime, FColor iColor) {
	
		message = iMessage;
		time = iTime;
		color = iColor;	
	
	}


};

/**
 * 
 */
UCLASS()
class PERSONALPROYECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDfont)
		UFont* hudFont;

	TArray<Message> messages;
	virtual void DrawHUD() override;
	void addMessage(Message msg);

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

void AMyHUD::DrawHUD() {


	Super::DrawHUD();
	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f * pad;
		float x = 0.f, y = c * messageH;
		DrawRect(FLinearColor::Black, c, y, Canvas->SizeX, messageH);
		DrawText(messages[c].message, messages[c].color, c + pad, y + pad, hudFont);
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		if (messages[c].time<0)
		{
			messages.RemoveAt(c);
		}
	}


}


void AMyHUD::addMessage(Message msg) {

	messages.Add(msg);

}
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TestingGroundsFPSHUD.generated.h"

UCLASS()
class ATestingGroundsFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATestingGroundsFPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


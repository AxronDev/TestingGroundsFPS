// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestingGroundsFPSGameMode.h"
#include "TestingGroundsFPSHUD.h"
#include "TestingGroundsFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingGroundsFPSGameMode::ATestingGroundsFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundsFPSHUD::StaticClass();
}

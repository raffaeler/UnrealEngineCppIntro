// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstPersonStartGameMode.h"
#include "FirstPersonStartCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirstPersonStartGameMode::AFirstPersonStartGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

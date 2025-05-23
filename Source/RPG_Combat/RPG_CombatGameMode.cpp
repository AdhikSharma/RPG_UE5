// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_CombatGameMode.h"
#include "RPG_CombatCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPG_CombatGameMode::ARPG_CombatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

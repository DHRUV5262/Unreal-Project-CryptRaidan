// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptRaidanGameMode.h"
#include "CryptRaidanCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h" 


ACryptRaidanGameMode::ACryptRaidanGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void ACryptRaidanGameMode::BeginPlay()
{
	Super::BeginPlay();
}


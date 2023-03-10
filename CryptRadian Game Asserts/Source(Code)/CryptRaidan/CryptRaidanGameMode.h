// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CryptRaidanGameMode.generated.h"

UCLASS(minimalapi)
class ACryptRaidanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACryptRaidanGameMode();



protected:
	
	
	virtual void BeginPlay() override;


private:


};




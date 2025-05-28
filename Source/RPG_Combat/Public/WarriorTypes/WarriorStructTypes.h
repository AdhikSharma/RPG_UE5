// Adhik Sharma All right reserved

#pragma once

#include "WarriorStructTypes.generated.h"

class UWarriorHeroAnimlayer;

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UWarriorHeroAnimlayer> WeaponAnimlayerToLink;

};


// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartupData/DataAsset_StartupDataBase.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "DataAsset_HeoStartupData.generated.h"

/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UDataAsset_HeoStartupData : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData", meta = (TitleProperty = "InputTag"))
	TArray<FWarriorHeroAbilitySet>	HeroStartupAbilitySets;
};

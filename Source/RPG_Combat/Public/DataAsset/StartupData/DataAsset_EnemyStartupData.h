// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartupData/DataAsset_StartupDataBase.h"
#include "DataAsset_EnemyStartupData.generated.h"

class UWarriorEnemyGameplayAbility;

/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UDataAsset_EnemyStartupData : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UWarriorEnemyGameplayAbility>> EnemyCombatAbilities;
	
};

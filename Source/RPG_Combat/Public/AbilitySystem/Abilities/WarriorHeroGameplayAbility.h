// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorCharacter;
class AWarriorHeroController;
class UHeroCombatController;
/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "WarriorAbility")
	AWarriorCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "WarriorAbility")
	AWarriorHeroController* GetWarriorHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "WarriorAbility")
	UHeroCombatController* HeroCombatControllerFromActorInfo();

private:
	TWeakObjectPtr<AWarriorCharacter> CachedWarriorCharacter;
	TWeakObjectPtr<AWarriorHeroController> CachedWarriorHeroController;
};

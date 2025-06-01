// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorCharacter;
class AWarriorHeroController;
class UHeroCombatComponent;
/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroController* GeHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpechandle(TSubclassOf<UGameplayEffect> EffectClass,float InWeaponBaseDamage,FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount);

private:
	TWeakObjectPtr<AWarriorCharacter> CachedWarriorCharacter;
	TWeakObjectPtr<AWarriorHeroController> CachedWarriorHeroController;
};

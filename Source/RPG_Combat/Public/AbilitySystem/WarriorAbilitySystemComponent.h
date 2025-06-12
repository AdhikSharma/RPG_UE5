// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "WarriorAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag InputTag);
	void OnAbilityInputReleased(const FGameplayTag InputTag);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability",meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities,int32 ApplyLevel,
								TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle  );

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	void RemoveGrantdHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSepcHandleToRemove);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability")
	bool TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate);
};

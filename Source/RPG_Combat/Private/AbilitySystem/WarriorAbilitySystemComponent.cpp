// Adhik Sharma All right reserved


#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag InputTag)
{
	if (!InputTag.IsValid()) 
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) continue;
		
		TryActivateAbility(AbilitySpec.Handle);

	}

}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag InputTag)
{

}

void UWarriorAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel,
													TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle)
{
	if (InDefaultWeaponAbilities.IsEmpty())
	{
		return;
	}

	for (const FWarriorHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		OutGrantedAbilitySpecHandle.AddUnique(GiveAbility(AbilitySpec));
	}

}

void UWarriorAbilitySystemComponent::RemoveGrantdHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSepcHandleToRemove)
{
	if (InSepcHandleToRemove.IsEmpty()) 
	{
		return;
	}

	for (const FGameplayAbilitySpecHandle& SpecHandle : InSepcHandleToRemove) 
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}

	InSepcHandleToRemove.Empty();

}

bool UWarriorAbilitySystemComponent::TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate)
{
	check(AbilityTagToActivate.IsValid());

	TArray<FGameplayAbilitySpec*> FoundAbilitySpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(
		AbilityTagToActivate.GetSingleTagContainer(),
		FoundAbilitySpecs);

	if (!FoundAbilitySpecs.IsEmpty())
	{
		const int RandomAbilityIndex = FMath::RandRange(0, FoundAbilitySpecs.Num() - 1);
		FGameplayAbilitySpec* SpecToActivate = FoundAbilitySpecs[RandomAbilityIndex];

		check(SpecToActivate);

		if (!SpecToActivate->IsActive())
		{
			return TryActivateAbility(SpecToActivate->Handle);
		}
	}

	return false;

}

// Adhik Sharma All right reserved


#include "DataAsset/StartupData/DataAsset_HeoStartupData.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "WarriorTypes/WarriorStructTypes.h"

void UDataAsset_HeoStartupData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    Super::GiveToAbilitySystemComponent(InASCToGive,ApplyLevel);

    for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartupAbilitySets)
    {
        if (!AbilitySet.IsValid()) continue;
        FGameplayAbilitySpec AbilitySpec;
        AbilitySpec.Ability = AbilitySet.AbilityToGrant ? AbilitySet.AbilityToGrant->GetDefaultObject<UGameplayAbility>() : nullptr;
        AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

        InASCToGive->GiveAbility(AbilitySpec);

    }
}

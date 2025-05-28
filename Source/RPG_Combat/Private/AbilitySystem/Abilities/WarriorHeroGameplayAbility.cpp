// Adhik Sharma All right reserved


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorCharacter.h"
#include "Controllers/WarriorHeroController.h"
#include "Components/Combat/HeroCombatComponent.h"

AWarriorCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorCharacter.IsValid())
	{
		CachedWarriorCharacter = Cast<AWarriorCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedWarriorCharacter.IsValid()? CachedWarriorCharacter.Get(): nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetWarriorHeroComponentFromActorInfo()
{
	if (!CachedWarriorHeroComponent.IsValid())
	{
		CachedWarriorHeroComponent = Cast<UHeroCombatComponent>(CurrentActorInfo->PlayerController);
	}

	return CachedWarriorHeroComponent.IsValid() ? CachedWarriorHeroComponent.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

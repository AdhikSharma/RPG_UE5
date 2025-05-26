// Adhik Sharma All right reserved


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorCharacter.h"
#include "Controllers/WarriorHeroController.h"
#include "Components/Combat/HeroCombatController.h"

AWarriorCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorCharacter.IsValid())
	{
		CachedWarriorCharacter = Cast<AWarriorCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedWarriorCharacter.IsValid()? CachedWarriorCharacter.Get(): nullptr;
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetWarriorHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->PlayerController);
	}

	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : nullptr;
}

UHeroCombatController* UWarriorHeroGameplayAbility::HeroCombatControllerFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatController();
}

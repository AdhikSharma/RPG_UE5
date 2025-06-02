// Adhik Sharma All right reserved


#include "Items/Weapons/WarriorHeroWeapon.h"

void AWarriorHeroWeapon::AssignGrantedAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle>& InSpecHandle)
{
	GrantedAbilitySpecHandle = InSpecHandle;

}

TArray<FGameplayAbilitySpecHandle> AWarriorHeroWeapon::GetGrantedAbilitySpecHandle() const
{
	return GrantedAbilitySpecHandle;
}

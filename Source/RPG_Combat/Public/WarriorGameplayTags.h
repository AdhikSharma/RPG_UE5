// Adhik Sharma All right reserved

#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags 
{
	/**Input Tags**/
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnEquipAxe);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);

	/**Player Tags**/

	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_UnEquip_Axe);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);
	

	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Axe);

	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	/**Enemy Tags**/

	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);

	/**Shared Tags**/
	RPG_COMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);

}

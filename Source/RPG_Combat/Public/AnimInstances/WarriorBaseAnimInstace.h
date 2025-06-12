// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"
#include "WarriorBaseAnimInstace.generated.h"

/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UWarriorBaseAnimInstace : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure,meta = (BlueprintThreadSafe))
	bool DoesOwnerHaveTag(FGameplayTag TagToCheck) const;
};

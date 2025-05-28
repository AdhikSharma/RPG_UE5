// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstace.h"
#include "WarriorHeroAnimlayer.generated.h"

class UWarriorHeroAnimInstance;
/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UWarriorHeroAnimlayer : public UWarriorBaseAnimInstace
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,meta = (BlueprintThreadSafe))
	UWarriorHeroAnimInstance* GetAnimHeroInstance() const;
	
};

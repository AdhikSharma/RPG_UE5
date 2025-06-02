// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorCharacterAnimInstace.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorCharacter;
/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstace
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AWarriorCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime;
	
};

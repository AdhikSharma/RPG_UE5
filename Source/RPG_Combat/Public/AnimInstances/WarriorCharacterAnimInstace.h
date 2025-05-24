// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstace.h"
#include "WarriorCharacterAnimInstace.generated.h"

class AWarriorBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UWarriorCharacterAnimInstace : public UWarriorBaseAnimInstace
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	AWarriorBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAccelaration;

};

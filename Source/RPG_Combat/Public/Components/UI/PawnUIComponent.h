// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPercentageChangedDelegate,float, NewPecent);

/**
 * 
 */
UCLASS()
class RPG_COMBAT_API UPawnUIComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPercentageChangedDelegate OnCurrentHealthChanged;
	
};

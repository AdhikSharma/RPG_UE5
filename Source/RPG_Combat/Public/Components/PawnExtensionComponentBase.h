// Adhik Sharma All right reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_COMBAT_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template<class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value,"'T' Template Parameter get GetPawn mush be derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const 
	{
		return GetOwningPawn<APawn>();
	}

	template<class T>
	T* GetOwningController() const 
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Parameter get GetController mush be derived from AController");
		return  GetOwningPawn<APawn>()->GetController<T>();
	}

	AController* GetOwningController() const 
	{
		return GetOwningPawn<APawn>()->GetController();
	}

		
};

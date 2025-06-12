// Adhik Sharma All right reserved


#include "AnimInstances/WarriorBaseAnimInstace.h"
#include "WarriorFunctionLibrary.h"

bool UWarriorBaseAnimInstace::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		 return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwningPawn,TagToCheck);
	}

	return false;
}

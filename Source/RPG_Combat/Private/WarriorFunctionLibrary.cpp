// Adhik Sharma All right reserved


#include "WarriorFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
	check(InActor);
 
	return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UWarriorAbilitySystemComponent* WarriorASC = NativeGetWarriorASCFromActor(InActor);

	if (!WarriorASC->HasMatchingGameplayTag(TagToAdd))
	{
		WarriorASC->AddLooseGameplayTag(TagToAdd);
		
	}
}

void UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UWarriorAbilitySystemComponent* WarriorASC = NativeGetWarriorASCFromActor(InActor);
	if (WarriorASC->HasMatchingGameplayTag(TagToRemove))
	{
		WarriorASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UWarriorFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UWarriorAbilitySystemComponent* WarriorASC = NativeGetWarriorASCFromActor(InActor);
	
	return WarriorASC->HasMatchingGameplayTag(TagToCheck);
	
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck)? EWarriorConfirmType::Yes:EWarriorConfirmType::No;
}

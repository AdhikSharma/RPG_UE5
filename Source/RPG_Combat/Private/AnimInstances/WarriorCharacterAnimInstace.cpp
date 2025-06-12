// Adhik Sharma All right reserved


#include "AnimInstances/WarriorCharacterAnimInstace.h"

#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"

void UWarriorCharacterAnimInstace::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComp = OwningCharacter->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstace::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComp) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAccelaration = OwningMovementComp->GetCurrentAcceleration().SizeSquared2D() > 0.f;

	LocomotionDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());

}

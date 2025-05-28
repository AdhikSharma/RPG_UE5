// Adhik Sharma All right reserved


#include "AnimInstances/Hero/WarriorHeroAnimlayer.h"
#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroAnimlayer::GetAnimHeroInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}

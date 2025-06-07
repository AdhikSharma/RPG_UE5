// Adhik Sharma All right reserved


#include "Interfaces/PawnUIInterface.h"
#include "Components/UI/EnemyUIComponent.h"

// Add default functionality here for any IPawnUIInterface functions that are not pure virtual.

UHeroUIComponent* IPawnUIInterface::GetHeroUIComponent() const
{
    return nullptr;
}

UEnemyUIComponent* IPawnUIInterface::GetEnemyUIComponent() const
{
    return nullptr;
}

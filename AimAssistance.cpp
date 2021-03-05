#include "AimAssistance.h"


void AimAssistance::shoot(MemoryManager& memObject)
{
	memory::writeMem<int>(memObject.getClientDLL() + offsets::dwForceAttack, 5, memObject.getHandle());
	memory::writeMem<int>(memObject.getClientDLL() + offsets::dwForceAttack, 4, memObject.getHandle());
}

bool AimAssistance::isTargetEnemyTeam(MemoryManager& memObject)
{
	const size_t entitySize = 0x10;   // i couldn't find a good explanation on why this is needed so if you can explain then please do
	 crosshairID = memory::readMem<DWORD>(localPlayerData::baseLocalPlayer + offsets::m_CrosshairId, memObject.getHandle());
	 targetInCross = memory::readMem<DWORD>(memObject.getClientDLL() + offsets::dwEntityList + (crosshairID - 1) * entitySize, memObject.getHandle());
	 targetTeam = memory::readMem<int>(targetInCross + offsets::m_iTeamNum, memObject.getHandle());
	 targetHealth = memory::readMem<int>(targetInCross + offsets::m_iHealth, memObject.getHandle());
	 if (targetHealth > 0)	return true;
	 return false;
}

void AimAssistance::triggerbot(MemoryManager& memObject)
{
	if(featureState::triggerbotState)
		if (isTargetEnemyTeam(memObject))
			shoot(memObject);
}



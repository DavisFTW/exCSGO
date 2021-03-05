#include "f_misc.h"

f_misc::f_misc()
{
	currentViewAngles	= { 0,0,0 };
	prevViewAngles		= { 0,0,0 };
}

void f_misc::bhop(MemoryManager& memManager, player& localPlayer)
{
	if (featureState::bhopState)
		if (localPlayer.EntityStruct.flags & FL_ONGROUND)
			if (GetAsyncKeyState(VK_SPACE))
				memory::writeMem<int>(memManager.getClientDLL() + offsets::dwForceJump, 6, memManager.getHandle());
}
void f_misc::autoStrafer(MemoryManager& memManager, player& localPlayer)
{
	if (featureState::autoStraferState)
	{
		DWORD clientState = memory::readMem<DWORD>(memManager.getEngineDLL() + offsets::dwClientState, memManager.getHandle());
		currentViewAngles = memory::readMem<QAngle>(clientState + offsets::dwClientState_ViewAngles, memManager.getHandle());
		if (!(localPlayer.EntityStruct.flags & FL_ONGROUND))
		{
			if (currentViewAngles.y > prevViewAngles.y)
				memory::writeMem<int>(memManager.getClientDLL() + offsets::dwForceLeft, 6, memManager.getHandle());
			if (currentViewAngles.y < prevViewAngles.y)
				memory::writeMem<int>(memManager.getClientDLL() + offsets::dwForceRight, 6, memManager.getHandle());
		}
		prevViewAngles = currentViewAngles;
	}
}

void f_misc::noFlash(MemoryManager& memManager)
{
	if (featureState::noFlashState)
	{
		float flashDuration = memory::readMem<DWORD>(localPlayerData::baseLocalPlayer + offsets::flFlashDuration, memManager.getHandle());   // I should add this to localPlayer struct but I have no idea how to do this since the offset for it is really really really far and I have no idea how I could add it manually
		if (flashDuration >= 0)
			memory::writeMem<float>(localPlayerData::baseLocalPlayer + offsets::flFlashDuration, 0.f, memManager.getHandle());
	}
}

void f_misc::fovChanger(MemoryManager& memManager, player& localPlayer)
{
	if (featureState::fovState)
		memory::writeMem<int>(localPlayerData::baseLocalPlayer + offsets::m_iDefaultFOV, 120, memManager.getHandle());
	else if (!featureState::fovState && localPlayer.EntityStruct.defaultFov != 90)
			memory::writeMem<int>(localPlayerData::baseLocalPlayer + offsets::m_iDefaultFOV, 90, memManager.getHandle());

	
}


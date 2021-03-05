#pragma once
#include <windows.h>
#include <cstdint>
namespace offsets
{
	extern DWORD localPlayer;
	extern DWORD m_iHealth;
	extern int m_fFlags;
	extern DWORD dwForceJump;
	extern DWORD flFlashDuration;
	extern DWORD dwClientState;
	extern DWORD dwClientState_State;
	extern int m_iDefaultFOV;
	extern bool m_bIsScoped;
	extern DWORD dwClientState;
	extern DWORD dwClientState_ViewAngles;
	extern int dwForceLeft;
	extern int dwForceRight;
	extern int m_CrosshairId;
	extern int m_iTeamNum;
	extern DWORD dwEntityList;
	extern DWORD dwForceAttack;
}

namespace localPlayerData
{
	extern uintptr_t baseLocalPlayer;
}

namespace featureState
{
	extern bool bhopState;
	extern bool noFlashState;
	extern bool fovState;
	extern bool autoStraferState;
	extern bool triggerbotState;
}

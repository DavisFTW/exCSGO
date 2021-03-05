#include "Offsets.h"


//offsets
DWORD offsets::localPlayer				= 0xD8B2DC;
DWORD offsets::m_iHealth				= 0x100;
DWORD offsets::dwForceJump				= 0x524CE94;
int   offsets::m_fFlags					= 0x104;
DWORD offsets::flFlashDuration			= 0xA420;
DWORD offsets::dwClientState			= 0x58EFE4;
DWORD offsets::dwClientState_State      = 0x108;
int   offsets::m_iDefaultFOV            = 0x332C;
bool  offsets::m_bIsScoped              = 0x3928;
DWORD offsets::dwClientState_ViewAngles = 0x4D90;
int   offsets::dwForceLeft				= 0x31D44A0;
int   offsets::dwForceRight				= 0x31D44C4;
int	  offsets::m_CrosshairId			= 0xB3E4;
int   offsets::m_iTeamNum				= 0xF4;
DWORD offsets::dwEntityList				= 0x4DA2F34;
DWORD offsets::dwForceAttack			= 0x31D4470;
// base
uintptr_t localPlayerData::baseLocalPlayer  = 0;


// toggles


bool featureState::bhopState			= false;
bool featureState::noFlashState			= false;
bool featureState::fovState				= false;
bool featureState::autoStraferState		= false;
bool featureState::triggerbotState		= false;


#include "PlayerClass.h"

void player::getLocalBasePTR(MemoryManager& obj)
{
	localPlayerData::baseLocalPlayer = memory::readMem<uintptr_t>(obj.getClientDLL() + offsets::localPlayer, obj.getHandle());
}

void player::getLocalPlayerData(MemoryManager& obj)
{
	EntityStruct = memory::readMem<playerStruct>(localPlayerData::baseLocalPlayer, obj.getHandle());   // i have no idea how to fix the "stack limit" exceeded, its just straight bullshit with vs

	std::cout << EntityStruct.health << std::endl;
}


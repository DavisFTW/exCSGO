#include "Misc.h"

int misc::inGame(MemoryManager& obj)   // I should probably move this somewhere else so I don't have a 1 file for 1 function, but I have no idea where I could fit it in 
{
	DWORD enginePointer = memory::readMem<DWORD>(obj.getEngineDLL() + offsets::dwClientState, obj.getHandle());
	return memory::readMem<int>(enginePointer + offsets::dwClientState_State, obj.getHandle());
}


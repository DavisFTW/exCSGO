#pragma once
#include <chrono>
#include <thread>
#include <vector>
#include "MemoryManager.h"
#include "Templates.h"
#include "defines.h"
#include "PlayerClass.h"

class f_misc
{
private:
	struct QAngle
	{
		float x, y, z;
	};

	QAngle currentViewAngles;
	QAngle prevViewAngles;
public:

	f_misc();
	void bhop(MemoryManager& memManager, player& localPlayer);
	void autoStrafer(MemoryManager& memManager, player& localPlayer);
	void noFlash(MemoryManager& memManager);
	void fovChanger(MemoryManager& memManager, player& localPlayer);
};


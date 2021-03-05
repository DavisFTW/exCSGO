#pragma once
#include "PlayerClass.h"
#include "MemoryManager.h"
class AimAssistance
{
private:
	DWORD crosshairID;
	DWORD targetInCross;
	int targetTeam;
	int targetHealth;
public:
	AimAssistance() : crosshairID(0), targetInCross(0), targetTeam(0), targetHealth(0) {}
	~AimAssistance() { ; }
	void shoot(MemoryManager& memObject);
	bool isTargetEnemyTeam(MemoryManager& memObject);
	void triggerbot(MemoryManager& memObject);
};


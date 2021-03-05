#pragma once
#include <cstdint>
#include <Windows.h>
#include "Templates.h"
#include "Offsets.h"


class player
{
public:
	struct playerStruct
	{
		char pad_0000[244]; //0x0000
		int32_t teamNum; //0x00F4
		char pad_00F8[8]; //0x00F8
		int32_t health; //0x0100
		int32_t flags; //0x0104
		char pad_0108[12512]; //0x0108
		int32_t fov; //0x31E8
		char pad_31EC[320]; //0x31EC
		int32_t defaultFov; //0x332C
		char pad_3330[3408]; //0x3330

	}EntityStruct;

	void getLocalBasePTR(MemoryManager& obj);
	void getLocalPlayerData(MemoryManager& obj);
	//void getEntityList(MemoryManager& obj);


};

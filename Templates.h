#pragma once
#include <Windows.h>
#include "MemoryManager.h"

// HOLY FUCK THIS IS BAD NO ERROR HANDLING AT ALL

namespace memory
{
	template <class T>
	T readMem(DWORD address, HANDLE handle)
	{
		T x;
		ReadProcessMemory(handle, (LPBYTE*)address, &x, sizeof(x), NULL);
		return x;
	}

	template <class T>
	T writeMem(DWORD address, T x, HANDLE handle)
	{
		WriteProcessMemory(handle, (LPBYTE*)address, &x, sizeof(x), NULL);
		return 0;
	}

}

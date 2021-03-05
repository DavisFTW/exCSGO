#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "Offsets.h"
class MemoryManager
{
private:
	DWORD procID;
	HANDLE gameHandle;
	DWORD clientDLL;
	DWORD engineDLL;
public:
	HANDLE getHandle() { return gameHandle; };
	MemoryManager();
	~MemoryManager();
	bool getProcessID(const char* processName);
	DWORD getModuleID(DWORD pID, const char* moduleName);
	void getgameDLL();

	DWORD getClientDLL() { return clientDLL; }
	DWORD getEngineDLL() { return engineDLL; }

	/*
	DWORD setClientDLL(DWORD dll) { clientDLL = dll; }
	DWORD setEngineDLL(DWORD dll) { engineDLL = dll; }
	DWORD setprocID(DWORD procID) { procID = procID; }
	DWORD setClientDLL(DWORD dll) { clientDLL = dll; }
	*/
};



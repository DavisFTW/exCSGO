#include "MemoryManager.h"
MemoryManager::MemoryManager()
{
	MemoryManager::gameHandle = 0;
	MemoryManager::procID     = 0;
	MemoryManager::clientDLL  = 0;
	MemoryManager::engineDLL  = 0;

}

MemoryManager::~MemoryManager()
{
	CloseHandle(MemoryManager::gameHandle);
}


bool MemoryManager::getProcessID(const char* processName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(PROCESSENTRY32);
	do
	{
		if (!strcmp(pEntry.szExeFile, processName))
		{
			CloseHandle(hSnapshot);
			MemoryManager::procID = pEntry.th32ProcessID;
			MemoryManager::gameHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pEntry.th32ProcessID);
			return true;
		}
	} while (Process32Next(hSnapshot, &pEntry));
	return false;
}

DWORD MemoryManager::getModuleID(DWORD pID, const char* moduleName)
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pID);
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(MODULEENTRY32);

	do
	{
		if (!strcmp(mEntry.szModule, moduleName))
		{
			CloseHandle(hModule);
			return (DWORD)mEntry.hModule;
		}
	} while (Module32Next(hModule, &mEntry));
	return false;
}

void MemoryManager::getgameDLL()
{
	DWORD serverbrowserDLL = 0;
	while (!serverbrowserDLL)
	{
		serverbrowserDLL = MemoryManager::getModuleID(MemoryManager::procID, "serverbrowser.dll");   // had some issues without this it gets clientDLL and engineDLL wrong, this ensures that the game is fully loaded
	}
	MemoryManager::clientDLL = MemoryManager::getModuleID(MemoryManager::procID, "client.dll");
	MemoryManager::engineDLL = MemoryManager::getModuleID(MemoryManager::procID, "engine.dll");

	std::cout << clientDLL << std::endl;
}


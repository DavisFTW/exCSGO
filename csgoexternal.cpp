//#include <string>
#include "MemoryManager.h"
#include "Misc.h"
#include "f_misc.h"
#include "PlayerClass.h"
#include "AimAssistance.h"
#define KRED   "\x1B[31m"
#define NORMAL "\x1b[37m"
#define GREEN  "\x1b[32m"

void enableFeature(bool &featureState, char cheatFunctionName[], SYSTEMTIME &object)  
{
    if (!featureState)
    {
        featureState = true;
        GetSystemTime(&object);
        printf("%s%c%02d:%02d%c%c%s%s%s%s%s%s\n", KRED , '[', object.wHour, object.wMinute, ']', ' ' ,NORMAL ,cheatFunctionName, " was turned ", GREEN, "ON", NORMAL);
    }
    else if (featureState)
    {
        featureState = false;
        GetSystemTime(&object);
        printf("%s%c%02d:%02d%c%c%s%s%s%s%s%s\n", KRED, '[', object.wHour, object.wMinute, ']', ' ', NORMAL, cheatFunctionName, " was turned ", KRED, "OFF", NORMAL);
    }
}

void init(MemoryManager& memObject, player& lPlayerObject)
{
    do
    {
        misc::inGame(memObject);
        if (GetAsyncKeyState(VK_INSERT))
            exit(-1);
    } while (misc::inGame(memObject) != 6);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); /// if this isn't here my localPlayerPTR gets read wrong( guess its too fast ? ? ? idk) 
    lPlayerObject.getLocalBasePTR(memObject);
}   

int main()
{
    MemoryManager mem;
    f_misc f_msc;
    SYSTEMTIME st;
    player lPlayer;
    AimAssistance aim;

    const int LENGHT = 42;   
    char cheatFunctionName[][LENGHT] = { "bhop", "noFlash", "fovChanger", "autostrafer", "triggerbot" };   /// std::string cannot be used in printf so this is a ghetto work-around
    bool processID = false;
    do
    {
        processID = mem.getProcessID("csgo.exe");
    } while (!processID);
    std::cout << "process found!" << std::endl;
    mem.getgameDLL();

    init(mem, lPlayer);
    std::cout << "cheat started" << std::endl;

    do
{
        lPlayer.getLocalPlayerData(mem);
        if (GetAsyncKeyState(VK_F1) & 1) 
            enableFeature(featureState::bhopState, cheatFunctionName[0], st);
        if (GetAsyncKeyState(VK_F2) & 1)
            enableFeature(featureState::noFlashState, cheatFunctionName[1], st);
        if (GetAsyncKeyState(VK_F3) & 1)
            enableFeature(featureState::fovState, cheatFunctionName[2], st);
        if (GetAsyncKeyState(VK_F4) & 1)
            enableFeature(featureState::autoStraferState, cheatFunctionName[3], st);
        if (GetAsyncKeyState(VK_F6) & 1)
            enableFeature(featureState::triggerbotState, cheatFunctionName[4], st);
        aim.triggerbot(mem);
        f_msc.bhop(mem, lPlayer);
        f_msc.noFlash(mem);
        f_msc.fovChanger(mem, lPlayer);
        f_msc.autoStrafer(mem, lPlayer);
        if (misc::inGame(mem) != 6)
        {
            std::cout << "user left the server" << std::endl;
            init(mem, lPlayer);
        }
    } while (!GetAsyncKeyState(VK_INSERT));
    return 0;
}



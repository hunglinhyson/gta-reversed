// dllmain.cpp : Defines the entry point for the DLL application.
#include "StdInc.h"

void InjectHooksMain(void);

void DisplayConsole(void)
{
    if (AllocConsole())
    {
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
}

void WINAPI DllThread(void)
{
    RwCamera * pRwCamera = *(RwCamera**)0xC1703C;

    // Fail if RenderWare has already been started
    if (pRwCamera) 
    {
        MessageBox(NULL, "gta_revered failed to load (RenderWare has already been started)", "Error", MB_ICONERROR | MB_OK);
        return;
    }

    DisplayConsole();
    InjectHooksMain();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)DllThread, NULL, NULL, NULL);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


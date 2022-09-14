#pragma once
#include <Windows.h>
#include "hooks.h"
#include <vector>
#include <detours.h>

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MH_Initialize();
		auto CurlAddr = FindPattern(CurlSet);
		auto CurlEasyAddr = FindPattern(CurlSetEasy);
		CSO = decltype(CSO)(CurlAddr);
		Yeet->Hook(CurlEasyAddr, (uintptr_t)CESO);
		AllocConsole();
		FILE* pFile;
		freopen_s(&pFile, ("CONOUT$"), "w", stdout);
		std::cout << "SodiumV3\n\nMade By GD#2022" << std::endl;
	}

	return TRUE;
}


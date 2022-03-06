#include <Windows.h>
#include <iostream>

#include "Scanner.h"
#include "Hooks.h"

void MainThread(HMODULE hModule) {
	HMODULE hSteamService = GetModuleHandleA("steamservice.dll");

	if (hSteamService) {
		if (InitVACHooks((void*)hSteamService))
			MessageBoxA(0, "VAC ha sido meado. Ahora puedes disfrutar Bv.", "VAC 420", MB_OK);
		else
			MessageBoxA(0, "Ha ocurrido un error, reinicia Steam como Administrador Bv", "VAC 420", MB_OK);
	}
	else
		MessageBoxA(0, "No se pudo encontrar steamservice.dll. Abre steam como administrador", "VAC 420", MB_OK);

	FreeLibraryAndExitThread(hModule, 0);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPARAM lParam) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
	}
}

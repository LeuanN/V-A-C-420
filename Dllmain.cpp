#include <Windows.h>
#include <iostream>

#include "Scanner.h"
#include "Hooks.h"

void kakapoto2(HMODULE hModule) {
	HMODULE hSteamService = GetModuleHandleA("steamservice.dll");

	if (hSteamService) {
		if (MouseGamerVAC((void*)hSteamService))
			MessageBoxA(0, "VAC ha sido meado. Ahora puedes disfrutar Bv.", "VAC 420", MB_OK);
		else
			MessageBoxA(0, "Ha ocurrido un error, reinicia Steam como Administrador Bv", "VAC 420", MB_OK);
	}
	else
		MessageBoxA(0, "No se pudo encontrar steamservice.dll. Abre steam como administrador", "VAC 420", MB_OK);

	FreeLibraryAndExitThread(hModule, 0);
}

void __forceinline kakapotokik() {
	std::srand(GetTickCount64());
	int x = rand() % 8;
	for (int i = 0; i < x; i++) {

		switch (x) {
		case 0:
			_asm {
				add eax, x
				sub eax, x
			}
		case 1:
			_asm {
				add ecx, x
				sub ecx, x
			}
		case 2:
			_asm {
				inc ecx
				dec ecx
			}
		case 3:
			_asm {
				mov eax, eax
				sub eax, x
				add eax, x
			}

		case 4:
			_asm {
				mov ecx, ecx
				sub ecx, x
				add ecx, x
			}
		case 5:
			_asm {
				sub eax, 1
				inc eax
			}
		case 6:
			_asm {
				pop ecx
				push ecx
			}
		case 7:
			_asm {
				dec eax
				add eax, 1
			}
		}
	}
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPARAM lParam) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)kakapoto2, hModule, 0, nullptr));
	}
}

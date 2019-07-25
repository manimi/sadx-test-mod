#include "SADXModLoader.h"
extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions &helperFunctions)

	{

		DataArray(int, HeldButtons, 0x3B0E3A8, 8);

		const char *buttonstrings[] = {
			"Suck",
			"My",
			"Dick"
		};

		void Teleport(uint8_t to, uint8_t from)
		{
			if (CharObj1Ptrs[to] == nullptr || CharObj1Ptrs[from] == nullptr)
				return;

			obj->Data1->Position = obj->Data1->Position;
			obj->Data1->Rotation = obj->Data1->Rotation;

			if (obj->Data1 != nullptr)
				obj->Data1->Speed = {};

			obj->Data1->Action = 1;
			obj->Data1->Status &= ~Status_Attack;
		}

		// Object patches
		WriteData((Uint8*)0x007A4DC4, PLAYER_COUNT); // Spring_Main
		WriteData((Uint8*)0x007A4FF7, PLAYER_COUNT); // SpringB_Main
		WriteData((Uint8*)0x0079F77C, PLAYER_COUNT); // SpringH_Main
		WriteData((Uint8*)0x004418B8, PLAYER_COUNT); // IsPlayerInsideSphere (could probably use a better name!)

			//Your code for the Init function
	}
	__declspec(dllexport) void __cdecl OnFrame()
	{
		//Your code for the OnFrame function
		for (int i = 0; i < PLAYER_COUNT; i++)
		{
			int btn = HeldButtons[i];
			if (btn & Buttons_Up)
				int textpos = (i * 19 + 1) << 16 | 0xA;
			Teleport(0, i);
			for (size_t j = 0; j < LengthOfArray(buttonstrings); j++)
			{
				DisplayDebugString(textpos++, (char *)buttonstrings[j]);
			}
		}
	}
	__declspec(dllexport) void __cdecl OnInput()
	{
		//Your code for the OnInput function
	}
}
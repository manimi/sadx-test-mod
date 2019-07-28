#include "stdafx.h"
#include "SADXModLoader.h"
#include "Trampoline.h"

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions &helperFunctions)
	{
		//Your code for the Init function
	}

	//Buttons_X = "X"
	//Buttons_Y = "Y"
	//Buttons_B = "B"
	//Buttons_A = "A"
	//Buttons_Left = Left_Stick - <
	//Buttons_Right = Left_Stick - >
	//Buttons_Up = Left_Stick - ^
    //Buttons_Down = Left_Stick - v
	//Buttons_C = Left_Bumper
	//Buttons_D = Right_Bumper
	//Buttons_L = Left_Trigger
	//Buttons_R = Right_Trigger
	//Buttons_Z = "Z Button?"

	const char *ImportantText = { "this is a test message" };



	__declspec(dllexport) void __cdecl OnFrame()
	{
		//Your code for the OnFrame function
	}
	__declspec(dllexport) void __cdecl OnInput()
	{
		if ((ControllerPointers[0]->HeldButtons & (Buttons_C)) == (Buttons_C))
		{
			int textpos = (1) << 16 | 0xA;

			SetDebugFontSize((unsigned short)(8 * min(VerticalStretch, HorizontalStretch)));

			SetDebugFontColor(0xFF00FF00);
			DisplayDebugString(textpos++, (char *)ImportantText);
			SetDebugFontColor(0xFFBFBFBF);
			SetDebugFontSize(8);
		}
	}
	__declspec(dllexport) void __cdecl OnExit()
	{
		//Your code for the OnExit function
	}
}
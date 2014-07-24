#include "DxLib.h"
#include "common.h"
#include "System.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(true);
	SetGraphMode(800,600,32);
	SetDrawScreen(DX_SCREEN_BACK);
	if (DxLib_Init()== -1)
	{
		return -1;
	}

	CSystem* sys = new CSystem();

	while(true)
	{
		ClearDrawScreen();

		sys->Run();

		ScreenFlip();
		if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	DxLib_End();
	return 0;
}
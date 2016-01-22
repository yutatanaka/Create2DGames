
#include "DxLib.h"
#include "GameManager.h"


char key[256];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	

	ChangeWindowMode(TRUE);

	SetGraphMode(Window::Width, Window::Height, Window::ColorBit);


	// DXライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}

	GameManager::GetInstance().Initialize();


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0)
	{
		GameManager::GetInstance().Update();
		GameManager::GetInstance().Draw();

	
	}

	// 画面を初期化
	ClearDrawScreen();

	// 裏画面の内容を表画面に反映
	ScreenFlip();

	DxLib_End();	
}
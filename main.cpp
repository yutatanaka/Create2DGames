
#include "DxLib.h"
#include "Key.h"
#include "GameManager.h"
#include "SceneManager.h"


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

	SceneManager::GetInstance();

	GameManager::GetInstance();

	SceneManager::GetInstance()->Initialize();

	GameManager::GetInstance()->Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && key.UpdateKey() == 0)
	{
		SceneManager::GetInstance()->Update();

		SceneManager::GetInstance()->Draw();
	}

	// 画面を初期化
	ClearDrawScreen();

	// 裏画面の内容を表画面に反映
	ScreenFlip();

	GameManager::DeleteInstance();

	SceneManager::DeleteInstance();

	DxLib_End();	

	return 0;
}
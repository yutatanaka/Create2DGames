
#include "DxLib.h"
#include "Key.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "fps.h"

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

	while ( true )
	{
		if(key.UpdateKey() != 0)break;
		if (ProcessMessage() != 0) break;
		if (ClearDrawScreen() != 0) break;
		
		SceneManager::GetInstance()->Draw();

		SceneManager::GetInstance()->Update();

		if (ScreenFlip() != 0)break;

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

#include "DxLib.h"
#include "GameManager.h"
#include "Field.h"
#include "Player.h"

char key[256];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(Window::Width, Window::Height, Window::ColorBit);

	gameManager.Initialize();

	// DXライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}

	Player player;
	Field field;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0)
	{
		field.Update();

		player.Update();
	}

	ClearDrawScreen();

	DxLib_End();	
}

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

	// DX���C�u��������������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
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
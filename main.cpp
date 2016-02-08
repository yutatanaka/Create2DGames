
#include "DxLib.h"
#include "Key.h"
#include "GameManager.h"
#include "SceneManager.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	

	ChangeWindowMode(TRUE);

	SetGraphMode(Window::Width, Window::Height, Window::ColorBit);


	// DX���C�u��������������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
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

	// ��ʂ�������
	ClearDrawScreen();

	// ����ʂ̓��e��\��ʂɔ��f
	ScreenFlip();

	GameManager::DeleteInstance();

	SceneManager::DeleteInstance();

	DxLib_End();	

	return 0;
}
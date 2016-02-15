
#include "DxLib.h"
#include "Key.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "fps.h"

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

	while ( true )
	{
		if(key.UpdateKey() != 0)break;
		if (ProcessMessage() != 0) break;
		if (ClearDrawScreen() != 0) break;
		
		SceneManager::GetInstance()->Draw();

		SceneManager::GetInstance()->Update();

		if (ScreenFlip() != 0)break;

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
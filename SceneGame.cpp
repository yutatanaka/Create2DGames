
#include "DxLib.h"
#include "SceneGame.h"
#include "GameManager.h"
#include "Player.h"

// �R���X�g���N�^
SceneGame::SceneGame() :
position(0, 0),
gameBackGroundHandle(0)
{
}

// �f�X�g���N�^
SceneGame::~SceneGame()
{
}

// ���������\�b�h
void SceneGame::Initialize()
{
	gameBackGroundHandle = LoadGraph("res/backgroundimage/backGroundSky.png");
}

// �X�V���\�b�h
void SceneGame::Update()
{
	GameManager::GetInstance()->Update();

	Draw();

	// Esc�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// �V�[�����^�C�g���ɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}

	// C�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		// �V�[�����N���A�ɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Clear);
	}

}

// �`�惁�\�b�h
void SceneGame::Draw()
{
	DrawGraph(position.x, position.y, gameBackGroundHandle, FALSE);

	GameManager::GetInstance()->Draw();

	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "C�L�[�������ƃN���A��ʂɐi�݂܂��B�B", GetColor(255, 255, 255));

	if (GameManager::GetInstance()->player->isLive == false)
	{
		DrawString(Width / 2, Height / 2, "G a m e O v e r", GetColor(255, 0, 0));
		DrawString(Width / 2, Height / 2 + 20, "Push Escape", GetColor(0, 0, 0));
	}
}
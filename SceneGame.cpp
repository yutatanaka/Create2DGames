
#include "DxLib.h"
#include "SceneGame.h"
#include "GameManager.h"

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
	gameBackGroundHandle = LoadGraph("res/background/gameBackGround.png");
}

// �X�V���\�b�h
void SceneGame::Update()
{
	GameManager::GetInstance()->Update();

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

	// E��������Ă�����
	if (CheckHitKey(KEY_INPUT_E) != 0)
	{
		// �V�[�����Q�[���I�[�o�[�ɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_GameOver);
	}
}

// �`�惁�\�b�h
void SceneGame::Draw()
{
	DrawGraph(position.x, position.y, gameBackGroundHandle, FALSE);

	GameManager::GetInstance()->Draw();

	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "C�L�[�������ƃN���A��ʂɖ߂�܂��B", GetColor(255, 255, 255));
	DrawString(0, 60, "E�L�[�������ƃQ�[���I�[�o�[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

#include "DxLib.h"
#include "SceneGame.h"
#include "GameManager.h"
#include "Fps.h"
#include "Sound.h"
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


	// Esc�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		PlaySoundFile("res/sound/decition.wav", DX_PLAYTYPE_BACK);
		
		// �V�[�����^�C�g���ɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}

	// �v���C���[�̉E�Ɖ��̃}�b�v�`�b�v��5��������
	if (CheckHitKey(KEY_INPUT_C) == 1)
	//if (GameManager::GetInstance()->player->CheckRight() == 5 || GameManager::GetInstance()->player->CheckUnder() == 5)
	{
		// �V�[�����N���A�ɕύX
		PlaySoundFile("res/sound/clear.wav", DX_PLAYTYPE_LOOP);
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Clear);
	}

}

// �`�惁�\�b�h
void SceneGame::Draw()
{

	DrawGraph(position.x, position.y, gameBackGroundHandle, FALSE);

	if (GameManager::GetInstance()->player->isLive == false)
	{
		SetFontSize(50);
		DrawString(1000, Height / 2, "G a m e O v e r...", GetColor(0, 0, 0));
		DrawString(1000, 530, "Push Escape", GetColor(0, 0, 0));
	}

	GameManager::GetInstance()->Draw();
	
	SetFontSize(50);
	DrawString(0, 0, "�����L�[�@�ړ�", GetColor(0, 0, 0));
	DrawString(0, 70, "SPACE�L�[�@�W�����v", GetColor(0, 0, 0));


}
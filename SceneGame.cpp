
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
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
	{
		PlaySoundMem(sound.dicitionSoundHandle, DX_PLAYTYPE_BACK);
		
		PlaySoundMem(sound.titleBackGroundHandle, TRUE);
		// �V�[�����^�C�g���ɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}

	// �v���C���[�̉E�Ɖ��̃}�b�v�`�b�v��5��������
	if (GameManager::GetInstance()->player->CheckRight() == 5 || GameManager::GetInstance()->player->CheckUnder() == 5)
	{
		// �V�[�����N���A�ɕύX
		StopSoundMem(sound.gameBackGroundHandle);
		PlaySoundMem(sound.clearBackGroundHandle, DX_PLAYTYPE_LOOP, TRUE);
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Clear);
	}

}

// �`�惁�\�b�h
void SceneGame::Draw()
{

	DrawGraph(position.x, position.y, gameBackGroundHandle, FALSE);

	if (GameManager::GetInstance()->player->isLive == false)
	{
		StopSoundMem(sound.gameBackGroundHandle);

		SetFontSize(50);
		DrawString(1000, Height / 2, "G a m e O v e r...", GetColor(0, 0, 0));
		DrawString(1000, 530, "Push ESCAPE�L�[", GetColor(0, 0, 0));
	}

	GameManager::GetInstance()->Draw();
	
	SetFontSize(50);
	DrawString(0, 0, "�����L�[�@�ړ�", GetColor(0, 0, 0));
	DrawString(0, 70, "SPACE�L�[�@�W�����v", GetColor(0, 0, 0));


}
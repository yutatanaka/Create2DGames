
#include "DxLib.h"
#include "SceneGame.h"
#include "GameManager.h"
#include "Fps.h"
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

	fps.Update();

	GameManager::GetInstance()->Update();

	Draw();

	fps.Draw();

	fps.Wait();

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
	
	SetFontSize(50);
	DrawString(0, 0, "�����L�[�@�ړ�", GetColor(0, 0, 0));
	DrawString(0, 70, "SPACE�L�[�@�W�����v", GetColor(0, 0, 0));

	if (GameManager::GetInstance()->player->isLive == false)
	{
		SetFontSize(50);
		DrawString(1000, Height / 2, "G a m e O v e r...", GetColor(0, 0, 0));
		DrawString(1000, 530, "Push Escape", GetColor(0, 0, 0));
	}
}
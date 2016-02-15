
#include "DxLib.h"
#include "SceneTitle.h"
#include "GameManager.h"
#include "Player.h"

// �R���X�g���N�^
SceneTitle::SceneTitle() :
position(0, 0),
titleBackGroundHandle(0)
{
}

// �f�X�g���N�^
SceneTitle::~SceneTitle()
{
}

// ���������\�b�h
void SceneTitle::Initialize()
{
	titleBackGroundHandle = LoadGraph("res/backgroundimage/backGroundTitle.png");
	PlaySoundFile("res/sound/titleBackGround.wav", DX_PLAYTYPE_LOOP);
}

// �X�V���\�b�h
void SceneTitle::Update()
{
	// G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_G) != 0)
	{
		StopSoundFile();
		PlaySoundFile("res/sound/decition.wav", DX_PLAYTYPE_BACK);
		PlaySoundFile("res/sound/gameBackGround.mp3", DX_PLAYTYPE_LOOP);
		// �����Ă��邩�ǂ����̃t���O��true�ɂ���
		GameManager::GetInstance()->player->isLive = true;
		// �������W�ɖ߂�
		GameManager::GetInstance()->player->position.x = GameManager::GetInstance()->player->kDefault_x;
		GameManager::GetInstance()->player->position.y = GameManager::GetInstance()->player->kDefault_y;
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Game);
	}
}

// �`�惁�\�b�h
void SceneTitle::Draw()
{
	DrawGraph(position.x, position.y, titleBackGroundHandle, FALSE);
}
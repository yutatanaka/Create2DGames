
#include "DxLib.h"
#include "SceneClear.h"
#include "Sound.h"

// �R���X�g���N�^
SceneClear::SceneClear() :
position(0, 0),
clearBackGroundHandle(0)
{
}

// �f�X�g���N�^
SceneClear::~SceneClear()
{
}

// ���������\�b�h
void SceneClear::Initialize()
{
	clearBackGroundHandle = LoadGraph("res/backgroundimage/backGroundClear.png");
}

// �X�V���\�b�h
void SceneClear::Update()
{
	// G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_G) == 1)
	{
		StopSoundMem(sound.gameBackGroundHandle);
		PlaySoundMem(sound.dicitionSoundHandle, DX_PLAYTYPE_BACK);
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Ending);
	}
}

// �`�惁�\�b�h
void SceneClear::Draw()
{
	DrawGraph(position.x, position.y, clearBackGroundHandle, FALSE);

}

#include "SceneTitle.h"

// �R���X�g���N�^
SceneTitle::SceneTitle()
{
}

// �f�X�g���N�^
SceneTitle::~SceneTitle()
{
}

// ���������\�b�h
void SceneTitle::Initialize()
{
}

// �X�V���\�b�h
void SceneTitle::Update()
{
	// G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_G) != 0)
	{
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Game);
	}
}

// �`�惁�\�b�h
void SceneTitle::Draw()
{
	DrawString(0, 0, "�^�C�g����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

#include "SceneClear.h"


// �R���X�g���N�^
SceneClear::SceneClear()
{
}

// �f�X�g���N�^
SceneClear::~SceneClear()
{
}

// ���������\�b�h
void SceneClear::Initialize()
{
}

// �X�V���\�b�h
void SceneClear::Update()
{
	// G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// �`�惁�\�b�h
void SceneClear::Draw()
{
	DrawString(0, 0, "�N���A��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ^�C�g����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}
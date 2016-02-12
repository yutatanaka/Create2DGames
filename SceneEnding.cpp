
#include "DxLib.h"
#include "SceneEnding.h"

// �R���X�g���N�^
SceneEnding::SceneEnding()
{

}

// �f�X�g���N�^
SceneEnding::~SceneEnding()
{

}

// ���������\�b�h
void SceneEnding::Initialize()
{

}

// �X�V���\�b�h
void SceneEnding::Update()
{
	// G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// �`�惁�\�b�h
void SceneEnding::Draw()
{
	DrawString(0, 0, "�G���f�B���O��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ^�C�g����ʂɐi�݂܂��B", GetColor(255, 255, 255));

	DrawString(Width / 2, Height / 2, "�G���f�B���O����B", GetColor(255, 255, 0));
}
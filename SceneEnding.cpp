
#include "DxLib.h"
#include "SceneGameOver.h"

// �R���X�g���N�^
SceneGameOver::SceneGameOver()
{

}

// �f�X�g���N�^
SceneGameOver::~SceneGameOver()
{

}

// ���������\�b�h
void SceneGameOver::Initialize()
{

}

// �X�V���\�b�h
void SceneGameOver::Update()
{
	// G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// �`�惁�\�b�h
void SceneGameOver::Draw()
{
	DrawString(0, 0, "�Q�[���I�[�o�[��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ^�C�g����ʂɐi�݂܂��B", GetColor(255, 255, 255));

	DrawString(Width / 2, Height / 2, "GAMEOVER", GetColor(255, 0, 0));
}
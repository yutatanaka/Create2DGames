
#include "DxLib.h"
#include "SceneClear.h"

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
	if (CheckHitKey(KEY_INPUT_E) != 0)
	{
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Ending);
	}
}

// �`�惁�\�b�h
void SceneClear::Draw()
{
	DrawGraph(position.x, position.y, clearBackGroundHandle, FALSE);

	DrawString(0, 0, "�N���A��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 50, "E�L�[�������ƃG���f�B���O��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}
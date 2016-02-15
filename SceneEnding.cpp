
#include "DxLib.h"
#include "SceneEnding.h"

// �R���X�g���N�^
SceneEnding::SceneEnding() :
gameOverPomeHandle(0)
{
}

// �f�X�g���N�^
SceneEnding::~SceneEnding()
{
}

// ���������\�b�h
void SceneEnding::Initialize()
{
	gameOverPomeHandle = LoadGraph("res/backgroundimage/gameOverPome.png");
}

// �X�V���\�b�h
void SceneEnding::Update()
{
	// G�L�[��������Ă�����
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		PlaySoundFile("res/sound/decition.wav", DX_PLAYTYPE_BACK);
		PlaySoundFile("res/sound/titleBackGround.wav", DX_PLAYTYPE_LOOP);
		// �V�[�����Q�[����ʂɕύX
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// �`�惁�\�b�h
void SceneEnding::Draw()
{
	DrawGraph(k_X-500, k_Y-300 , gameOverPomeHandle, TRUE);

	DrawString(k_X, k_Y-300 , "�n�E�X��GO�`�@�J���`�[��", kColor_White);

	DrawString(k_X, k_Y -200, "�v�����i�[���v���O���}�[", kColor_White);
	DrawString(k_X, k_Y -150, "�c���@�D��", kColor_White);

	DrawString(k_X, k_Y -50, "�f�U�C�i�[", kColor_White);
	DrawString(k_X, k_Y, "�����@�c��   ���� �Đ�", kColor_White);

	DrawString(Width -400, k_Y + 400, "Push�@Esc�L�[", kColor_White);

}
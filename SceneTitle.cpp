
#include "DxLib.h"
#include "SceneTitle.h"

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
	titleBackGroundHandle = LoadGraph("res/background/titleBackGround.png");
	                                
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
	DrawGraph(position.x, position.y, titleBackGroundHandle, FALSE);

	DrawString(0, 0, "�^�C�g����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}
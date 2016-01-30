
#include "DxLib.h"
#include "GameManager.h"
#include "BackGround.h"

// �R���X�g���N�^
BackGround::BackGround() :
x(),
y(),
backGraphicHandle()
{
}

// ���������\�b�h
void BackGround::Initialize()
{
	backGraphicHandle = LoadGraph("res/background/backGroundImage.png");
}

// �X�V���\�b�h
void BackGround::Update()
{

}

// �`�惁�\�b�h
void BackGround::Draw()
{
	DrawGraph(x, y, backGraphicHandle, FALSE);
}

#include "DxLib.h"
#include "GameManager.h"
#include "BackGround.h"

// �R���X�g���N�^
BackGround::BackGround() :
height(Height),
width(Width),
backGraphicHandle()
{
}

// ���������\�b�h
void BackGround::Initialize()
{
	backGraphicHandle = LoadGraphScreen(0, 0, "res/background/backGrounddImage.png", TRUE);
}

// �X�V���\�b�h
void BackGround::Update()
{

}

// �`�惁�\�b�h
void BackGround::Draw()
{
	DrawGraph(0 + width, 0 + height, backGraphicHandle, TRUE);
}
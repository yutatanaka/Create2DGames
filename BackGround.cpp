
#include "DxLib.h"
#include "GameManager.h"
#include "BackGround.h"

// コンストラクタ
BackGround::BackGround() :
height(Height),
width(Width),
backGraphicHandle()
{
}

// 初期化メソッド
void BackGround::Initialize()
{
	backGraphicHandle = LoadGraphScreen(0, 0, "res/background/backGrounddImage.png", TRUE);
}

// 更新メソッド
void BackGround::Update()
{

}

// 描画メソッド
void BackGround::Draw()
{
	DrawGraph(0 + width, 0 + height, backGraphicHandle, TRUE);
}

#include "DxLib.h"
#include "GameManager.h"
#include "BackGround.h"

// コンストラクタ
BackGround::BackGround() :
x(),
y(),
backGraphicHandle()
{
}

// 初期化メソッド
void BackGround::Initialize()
{
	backGraphicHandle = LoadGraph("res/background/backGroundImage.png");
}

// 更新メソッド
void BackGround::Update()
{

}

// 描画メソッド
void BackGround::Draw()
{
	DrawGraph(x, y, backGraphicHandle, FALSE);
}
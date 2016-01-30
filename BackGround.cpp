
#include "DxLib.h"
#include "BackGround.h"

// コンストラクタ
BackGround::BackGround() :
height(),
width(),
backGraphicHandle()
{
}

// 初期化メソッド
void BackGround::Initialize()
{
	backGraphicHandle = LoadGraphScreen(0, 0, "")
}

// 更新メソッド
void BackGround::Update()
{

}

// 描画メソッド
void BackGround::Draw()
{

}
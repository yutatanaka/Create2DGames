
#include "DxLib.h"
#include "SceneClear.h"

// コンストラクタ
SceneClear::SceneClear() :
position(0, 0),
clearBackGroundHandle(0)
{
}

// デストラクタ
SceneClear::~SceneClear()
{
}

// 初期化メソッド
void SceneClear::Initialize()
{
	clearBackGroundHandle = LoadGraph("res/backgroundimage/backGroundClear.png");
}

// 更新メソッド
void SceneClear::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_G) != 0)
	{
		// シーンをゲーム画面に変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Ending);
	}
}

// 描画メソッド
void SceneClear::Draw()
{
	DrawGraph(position.x, position.y, clearBackGroundHandle, FALSE);

}
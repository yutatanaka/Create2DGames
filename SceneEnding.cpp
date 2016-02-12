
#include "DxLib.h"
#include "SceneEnding.h"

// コンストラクタ
SceneEnding::SceneEnding()
{

}

// デストラクタ
SceneEnding::~SceneEnding()
{

}

// 初期化メソッド
void SceneEnding::Initialize()
{

}

// 更新メソッド
void SceneEnding::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// シーンをゲーム画面に変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// 描画メソッド
void SceneEnding::Draw()
{
	DrawString(0, 0, "エンディング画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとタイトル画面に進みます。", GetColor(255, 255, 255));

	DrawString(Width / 2, Height / 2, "エンディングだよ。", GetColor(255, 255, 0));
}
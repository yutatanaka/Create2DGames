
#include "SceneClear.h"


// コンストラクタ
SceneClear::SceneClear()
{
}

// デストラクタ
SceneClear::~SceneClear()
{
}

// 初期化メソッド
void SceneClear::Initialize()
{
}

// 更新メソッド
void SceneClear::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// シーンをゲーム画面に変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// 描画メソッド
void SceneClear::Draw()
{
	DrawString(0, 0, "クリア画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとタイトル画面に進みます。", GetColor(255, 255, 255));
}
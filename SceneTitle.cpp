
#include "SceneTitle.h"

// コンストラクタ
SceneTitle::SceneTitle()
{
}

// デストラクタ
SceneTitle::~SceneTitle()
{
}

// 初期化メソッド
void SceneTitle::Initialize()
{
}

// 更新メソッド
void SceneTitle::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_G) != 0)
	{
		// シーンをゲーム画面に変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Game);
	}
}

// 描画メソッド
void SceneTitle::Draw()
{
	DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}
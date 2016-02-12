
#include "DxLib.h"
#include "SceneGameOver.h"

// コンストラクタ
SceneGameOver::SceneGameOver()
{

}

// デストラクタ
SceneGameOver::~SceneGameOver()
{

}

// 初期化メソッド
void SceneGameOver::Initialize()
{

}

// 更新メソッド
void SceneGameOver::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// シーンをゲーム画面に変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// 描画メソッド
void SceneGameOver::Draw()
{
	DrawString(0, 0, "ゲームオーバー画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとタイトル画面に進みます。", GetColor(255, 255, 255));

	DrawString(Width / 2, Height / 2, "GAMEOVER", GetColor(255, 0, 0));
}
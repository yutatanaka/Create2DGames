
#include "DxLib.h"
#include "SceneGame.h"
#include "GameManager.h"
#include "Fps.h"
#include "Player.h"

// コンストラクタ
SceneGame::SceneGame() :
position(0, 0),
gameBackGroundHandle(0)
{
}

// デストラクタ
SceneGame::~SceneGame()
{
}

// 初期化メソッド
void SceneGame::Initialize()
{
	gameBackGroundHandle = LoadGraph("res/backgroundimage/backGroundSky.png");
}

// 更新メソッド
void SceneGame::Update()
{

	fps.Update();

	GameManager::GetInstance()->Update();

	Draw();

	fps.Draw();

	fps.Wait();

	// Escキーが押されていたら
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		// シーンをタイトルに変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}

	// Cキーが押されていたら
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		// シーンをクリアに変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Clear);
	}

}

// 描画メソッド
void SceneGame::Draw()
{
	DrawGraph(position.x, position.y, gameBackGroundHandle, FALSE);

	GameManager::GetInstance()->Draw();

	DrawString(0, 0, "←→キー　移動", GetColor(255, 255, 255));
	DrawString(0, 20, "SPACEキー　ジャンプ", GetColor(255, 255, 255));

	if (GameManager::GetInstance()->player->isLive == false)
	{
		DrawString(Width / 2, Height / 2, "G a m e O v e r", GetColor(255, 0, 0));
		DrawString(Width / 2, Height / 2 + 20, "Push Escape", GetColor(0, 0, 0));
	}
}

#include "DxLib.h"
#include "SceneGame.h"
#include "GameManager.h"

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
	gameBackGroundHandle = LoadGraph("res/background/gameBackGround.png");
}

// 更新メソッド
void SceneGame::Update()
{
	GameManager::GetInstance()->Update();

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

	// Eを押されていたら
	if (CheckHitKey(KEY_INPUT_E) != 0)
	{
		// シーンをゲームオーバーに変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_GameOver);
	}
}

// 描画メソッド
void SceneGame::Draw()
{
	DrawGraph(position.x, position.y, gameBackGroundHandle, FALSE);

	GameManager::GetInstance()->Draw();

	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
	DrawString(0, 40, "Cキーを押すとクリア画面に戻ります。", GetColor(255, 255, 255));
	DrawString(0, 60, "Eキーを押すとゲームオーバー画面に戻ります。", GetColor(255, 255, 255));
}
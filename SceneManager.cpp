
#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;
static eScene scene = eScene_Title;	// シーン管理変数


// コンストラクタ
SceneManager::SceneManager()
{
	sceneTitle = new SceneTitle();

	sceneGame = new SceneGame();

	sceneClear = new SceneClear();

	sceneGameOver = new SceneGameOver();
}

// デストラクタ
SceneManager::~SceneManager()
{
	delete sceneTitle;

	delete sceneGame;

	delete sceneClear;

	delete sceneGameOver;
}

// 初期化メソッド
void SceneManager::Initialize()
{
}

// 更新メソッド
void SceneManager::Update()
{
	switch (scene)				// シーンによって処理を分岐
	{
	case eScene_Title:			// 現在の画面がタイトルなら
		sceneTitle->Update();	// タイトル画面の更新処理をする
		break;
	case eScene_Game:			// 現在の画面がゲームなら
		sceneGame->Update();	// ゲーム画面の更新処理をする
		break;
	case eScene_Clear:			// 現在の画面がクリアなら
		sceneClear->Update();	// クリア画面の更新処理をする
		break;
	case eScene_GameOver:		// 現在の画面がゲームオーバーなら
		sceneGameOver->Update();// ゲームオーバー画面の更新処理をする
		break;

	}
}

// 描画メソッド
void SceneManager::Draw()
{
	switch (scene)				// シーンによって処理を分岐
	{
	case eScene_Title:			// 現在の画面がタイトルなら
		sceneTitle->Draw();		// タイトル画面の描画処理をする
		break;
	case eScene_Game:			// 現在の画面がゲームなら
		sceneGame->Draw();		// ゲーム画面の描画処理をする
		break;
	case eScene_Clear:			// 現在の画面がクリアなら
		sceneClear->Draw();		// クリア画面の描画処理をする
		break;
	case eScene_GameOver:		// 現在の画面がゲームオーバーなら
		sceneGameOver->Draw();	// ゲームオーバー画面の描画処理をする
		break;
	}


}

// 引数 nextScene シーンを変更する
void SceneManager::SceneManager_ChangeScene(eScene nextScene)
{
	scene = nextScene;
}
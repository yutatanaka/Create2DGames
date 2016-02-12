
#pragma once

#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneEnding.h"

// シーンの内容
typedef enum
{
	eScene_Title,		// タイトル画面
	eScene_Game,		// ゲーム画面
	eScene_Clear,		// クリア画面
	eScene_Ending,		// エンディング画面

}eScene ;

class SceneTitle;
class SceneGame;
class SceneClear;
class SceneEnding;

class SceneManager
{
private:

	// コンストラクタ
	SceneManager();


public:

	// デストラクタ
	~SceneManager();

	// シングルトン
	static SceneManager* GetInstance()
	{
		if (nullptr == instance)
		{
			instance = new SceneManager();
		}
		return instance;
	}

	static SceneManager* DeleteInstance()
	{
		delete instance;

		return instance;
	}

	// 初期化メソッド
	void Initialize();

	// 更新メソッド
	void Update();

	// 描画メソッド
	void Draw();

	// 引数 nextScene にシーンを変更する
	void SceneManager_ChangeScene(eScene nextScene);

public:

	// 各クラスのインスタンスを生成
	static SceneManager* instance;

	SceneTitle *sceneTitle;

	SceneGame *sceneGame;

	SceneClear *sceneClear;

	SceneEnding *sceneEnding;

};
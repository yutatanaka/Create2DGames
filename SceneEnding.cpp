
#include "DxLib.h"
#include "SceneEnding.h"
#include "Sound.h"

// コンストラクタ
SceneEnding::SceneEnding() :
gameOverPomeHandle(0)
{
}

// デストラクタ
SceneEnding::~SceneEnding()
{
}

// 初期化メソッド
void SceneEnding::Initialize()
{
	gameOverPomeHandle = LoadGraph("res/backgroundimage/gameOverPome.png");
}

// 更新メソッド
void SceneEnding::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		StopSoundMem(sound.clearBackGroundHandle);

		PlaySoundMem(sound.dicitionSoundHandle, DX_PLAYTYPE_BACK);
		PlaySoundMem(sound.titleBackGroundHandle, DX_PLAYTYPE_LOOP);
		// シーンをゲーム画面に変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}
}

// 描画メソッド
void SceneEnding::Draw()
{
	DrawGraph(k_X-500, k_Y-300 , gameOverPomeHandle, TRUE);

	DrawString(k_X, k_Y-300 , "ハウスへGO〜", kColor_White);

	DrawString(k_X, k_Y -200, "プランナー兼プログラマー", kColor_White);
	DrawString(k_X, k_Y -150, "田中　優太", kColor_White);

//	DrawString(k_X, k_Y -50, "デザイナー", kColor_White);
//	DrawString(k_X, k_Y, "阿部　慶照   高橋 夏生", kColor_White);

	DrawString(Width -400, k_Y + 400, "Push　Escキー", kColor_White);

}
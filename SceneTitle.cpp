
#include "DxLib.h"
#include "SceneTitle.h"
#include "GameManager.h"
#include "Sound.h"
#include "Player.h"

// コンストラクタ
SceneTitle::SceneTitle() :
position(0, 0),
titleBackGroundHandle(0)
{
}

// デストラクタ
SceneTitle::~SceneTitle()
{
}

// 初期化メソッド
void SceneTitle::Initialize()
{
	titleBackGroundHandle = LoadGraph("res/backgroundimage/backGroundTitle.png");
	PlaySoundMem(sound.titleBackGroundHandle, DX_PLAYTYPE_LOOP, TRUE);
}

// 更新メソッド
void SceneTitle::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_G) != 0)
	{
		StopSoundMem(sound.titleBackGroundHandle);

		PlaySoundMem(sound.dicitionSoundHandle, DX_PLAYTYPE_BACK);
		PlaySoundMem(sound.gameBackGroundHandle, DX_PLAYTYPE_LOOP, TRUE);
		// 生きているかどうかのフラグをtrueにする
		GameManager::GetInstance()->player->isLive = true;
		// 初期座標に戻す
		GameManager::GetInstance()->player->position.x = GameManager::GetInstance()->player->kDefault_x;
		GameManager::GetInstance()->player->position.y = GameManager::GetInstance()->player->kDefault_y;
		// シーンをゲーム画面に変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Game);
	}
}

// 描画メソッド
void SceneTitle::Draw()
{
	DrawGraph(position.x, position.y, titleBackGroundHandle, FALSE);
}
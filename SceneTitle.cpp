
#include "DxLib.h"
#include "SceneTitle.h"
#include "GameManager.h"
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
	PlaySoundFile("res/sound/titleBackGround.wav", DX_PLAYTYPE_LOOP);
}

// 更新メソッド
void SceneTitle::Update()
{
	// Gキーが押されていたら
	if (CheckHitKey(KEY_INPUT_G) != 0)
	{
		StopSoundFile();
		PlaySoundFile("res/sound/decition.wav", DX_PLAYTYPE_BACK);
		PlaySoundFile("res/sound/gameBackGround.mp3", DX_PLAYTYPE_LOOP);
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
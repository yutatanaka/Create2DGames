
#include "DxLib.h"
#include "SceneGame.h"
#include "GameManager.h"
#include "Fps.h"
#include "Sound.h"
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

	GameManager::GetInstance()->Update();


	// Escキーが押されていたら
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		PlaySoundMem(sound.dicitionSoundHandle, DX_PLAYTYPE_BACK);
		
		// シーンをタイトルに変更
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Title);
	}

	// プレイヤーの右と下のマップチップが5だったら
	if (CheckHitKey(KEY_INPUT_C) == 1)
	//if (GameManager::GetInstance()->player->CheckRight() == 5 || GameManager::GetInstance()->player->CheckUnder() == 5)
	{
		// シーンをクリアに変更
		StopSoundFile();
		PlaySoundMem(sound.clearBackGroundHandle, DX_PLAYTYPE_LOOP, TRUE);
		SceneManager::GetInstance()->SceneManager_ChangeScene(eScene_Clear);
	}

}

// 描画メソッド
void SceneGame::Draw()
{

	DrawGraph(position.x, position.y, gameBackGroundHandle, FALSE);

	if (GameManager::GetInstance()->player->isLive == false)
	{
		StopSoundMem(sound.gameBackGroundHandle);
		SetFontSize(50);
		DrawString(1000, Height / 2, "G a m e O v e r...", GetColor(0, 0, 0));
		DrawString(1000, 530, "Push Escape", GetColor(0, 0, 0));
	}

	GameManager::GetInstance()->Draw();
	
	SetFontSize(50);
	DrawString(0, 0, "←→キー　移動", GetColor(0, 0, 0));
	DrawString(0, 70, "SPACEキー　ジャンプ", GetColor(0, 0, 0));


}
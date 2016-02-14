
#pragma once

#include "GameManager.h"

class SceneEnding
{
public:

	// コンストラクタ
	SceneEnding();

	// デストラクタ
	~SceneEnding();

	// 初期化メソッド
	void Initialize();

	// 更新メソッド
	void Update();

	// 描画メソッド
	void Draw();

public:

	// ゲームオーバー時の画像ハンドル
	int gameOverPomeHandle;

	// 描画時の座標
	
	// x座標
	const int k_X = 700;
	
	// y座標
	const int k_Y = 480;

	const int kColor_White = GetColor(255, 255, 255);

};
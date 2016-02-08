
#pragma once

#include "Vec2.h"

class SceneGame
{
public:

	// コンストラクタ
	SceneGame();

	// デストラクタ
	~SceneGame();

	// 初期化メソッド
	void Initialize();

	// 更新メソッド
	void Update();

	// 描画メソッド
	void Draw();

public:

	// 座標
	Vec2 position;

	// 背景の画像ハンドル
	int gameBackGroundHandle;

};
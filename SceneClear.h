
#pragma once

#include "GameManager.h"
#include "Vec2.h"

class SceneClear
{
public:

	// コンストラクタ
	SceneClear();

	// デストラクタ
	~SceneClear();

	// 初期化メソッド
	void Initialize();

	// 更新メソッド
	void Update();

	// 描画メソッド
	void Draw();

public:

	// 座標
	Vec2 position;

	// クリア画面背景の格納用ハンドル
	int clearBackGroundHandle;
};
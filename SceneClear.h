
#pragma once

#include "GameManager.h"
#include "Vec2f.h"

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
	Vec2f position;

	// クリア画面背景の格納用ハンドル
	int clearBackGroundHandle;
};

#pragma once 

#include "GameManager.h"
#include "Vec2.h"

class SceneTitle
{
public:

	// コンストラクタ
	SceneTitle();

	// デストラクタ
	~SceneTitle();

	// 初期化メソッド
	void Initialize();

	// 更新メソッド
	void Update();

	// 描画メソッド
	void Draw();

public:

	// 座標
	Vec2 position;

	// クリア画面の背景ハンドル
	int titleBackGroundHandle;
};
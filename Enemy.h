

#pragma once

#include "GameManager.h"
#include "Vec2f.h"
#include "Vec2i.h"
#include "Player.h"

class Enemy
{
public:

	// コンストラクタ
	Enemy();

	// デストラクタ
	~Enemy();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// 移動処理
	void Move();

	// 当たり判定
	void BeeCheckHit();


public:

	// 座標
	int bee_x, bee_y;

	// 移動係数
	Vec2f move;				

	// 距離
	Vec2i distance;
	
	// 幅、高さ
	int width, height;			

private:

	// 蜂のグラフィックハンドル格納用変数
	int beeGraphicHandle;

	// 虫取り網のグラフィックハンドル格納用変数
	int butterflyNetGraphicHandle;

};


#pragma once

#include "GameManager.h"
#include "Vec2f.h"
#include "Player.h"

class MoveFloor
{
public:

	// コンストラクタ
	MoveFloor();

	// デストラクタ
	~MoveFloor();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// 移動処理
	void Move();

	// 当たり判定
	// true..当たっている false...当たっていない
	void MoveFloorCheckHit(Player& player, int x, int y);


public:

	// 床のポジション
	Vec2f pos;			

	// 移動係数
	Vec2f move;				

	// スピード
	float speed;			

	// 幅、高さ
	int width, height;		
	
	// 最小座標
	Vec2f _min;

	// 最大座標
	Vec2f _max;				

	// 色
	int color;

};

extern MoveFloor moveFloor;
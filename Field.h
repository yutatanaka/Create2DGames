
#pragma once

#include "Vec2.h"
#include "Player.h"

#define MAP_SIZE 64		// マップチップ1つのドットサイズ
#define MAP_WIDTH 16	// マップの幅
#define MAP_HEIGHT 12	// マップの縦長さ

class Field
{
public:
	
	// コンストラクタ
	Field();

	// デストラクタ
	~Field();

	// 更新メソッド
	void Update();
	
	// 描画メソッド
	void Draw();

	// 当たり判定メソッド
	bool CollisionDetection(Vec2 pos);

public:

	// マップのデータ 
	int MapData[MAP_HEIGHT][MAP_WIDTH];


private:

	// x軸、ｙ軸
	int x_axis, y_axis;
};


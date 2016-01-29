
#pragma once

#include <vector>
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

	// プレイヤーと床との当たり判定メソッド
	void CheckHit(Player& player);


public:

	// マップのデータ 
	int mapData[MAP_HEIGHT][MAP_WIDTH];

	// 座標
	int x, y;

	// 高さ、幅
	int width, height;

private:

	// フィールド用のハンドル
	int blockGraphicHandle;

};

//std::vector<std::vector<int>> boxArray;

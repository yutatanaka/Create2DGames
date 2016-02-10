
#pragma once

#include <vector>
#include "Vec2f.h"
#include "Player.h"

#define MAP_SIZE 64		// マップチップ1つのドットサイズ
#define MAP_WIDTH 25	// マップの幅
#define MAP_HEIGHT 15	// マップの縦長さ


class Field
{
public:
	
	// コンストラクタ
	Field();

	// 初期化メソッド
	void Initialize();

	// 更新メソッド
	void Update();
	
	// 描画メソッド
	void Draw();

	// プレイヤーと床との当たり判定メソッド
	void CheckHit(Player& player, int x, int y);


public:

	// マップのデータ 
	int mapData[MAP_HEIGHT][MAP_WIDTH];

	// 座標
	int x, y;

	// 幅
	int boxWidth, boxHeight;

	//距離をはかる
	Vec2f distance;

private:

	// フィールド用のハンドル
	int groundGraphicHandle;

};
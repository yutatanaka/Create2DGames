
#pragma once

#include "Vec2.h"

class Player
{
public:
	
	Player();

	void Update();

private:

	// 移動処理
	void Input();

	// 描画処理
	void Draw();

private:

	// キャラクターの座標
	Vec2f position;

	// 画像の幅
	int width, height;

	// グラフィックハンドル格納用配列
	int graphicHandle[12];

	// 移動係数
	float move;

	// 横方向と縦方向のカウント数
	int xCount, yCount;

	// 添字用変数
	int imageX, imageY, result;

	// 生きてるかどうかのフラグ
	bool isLive;

////////////////////////////////////

	// 歩く速度(定数)
	const int kSpeed = 3;
};

// キー取得用配列
extern char key[256];
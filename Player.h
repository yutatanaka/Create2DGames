
#pragma once

#include "Vec2.h"

class Player
{
private:

	// 移動処理
	void Input();

	// 重力処理
	void Gravity();

public: 

	// コンストラクタ
	Player();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// キャラクターの現在、座標取得
	Vec2 GetPosition()const{ return position; }

private:


	// 移動係数
	float move;

	// ジャンプ力
	float jumpPower;

	// ジャンプしているかどうかのフラグ
	bool isJump;

	// 生きてるかどうかのフラグ
	bool isLive;

////////////////////////////////////

	// 歩く速度(定数)
	const int kSpeed = 3;

public:

	// キャラクターの座標
	Vec2 position;

	// キャラクターの大きさ
	Vec2 scale;

	// 画像の幅
	int width, height;

	// グラフィックハンドル格納用配列
	int graphicHandle[12];

	// テスト用ハンドル
	//int graphicHandle;

	// 横方向と縦方向のカウント数
	int xCount, yCount;

	// 添字用変数
	int imageX, imageY, result;
};


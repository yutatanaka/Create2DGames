
#pragma once

#include "GameManager.h"
#include "Vec2.h"
#include "Field.h"

class Player
{
private:

	// 入力処理メソッド
	void Input();

	// 重力処理メソッド
	void Gravity();

	// ジャンプ処理メソッド
	void Jump();

	// 移動制御メソッド
	void MovementControl();

public: 

	// コンストラクタ
	Player();

	// 初期化処理メソッド
	void Initialize();

	// 更新処理メソッド
	void Update();

	// 描画処理メソッド
	void Draw();

	// 当たっているときの処理メソッド
	void IsHit(Field& field);

	// キャラクターの現在、座標取得メソッド
	Vec2 GetPosition()const{ return position; }

private:

	// 移動係数
	float move;

	// ジャンプ力
	float jumpPower;

	// 一時的にy座標の位置を保存
	float yTemp;

	// 少し前のｙ座標
	float yPrev;

	// ジャンプしているかどうかのフラグ
	bool isJump;

	// 生きてるかどうかのフラグ
	bool isLive;

////////////////////////////////////

	// 歩く速度(定数)
	const int kSpeed = 3;

	// 1ピクセル分余白を持たせる(定数)
	const int kMargin = 1;

public:

	// キャラクターの座標
	Vec2 position;

	// キャラクターの大きさ
	Vec2 scale;

	// 画像の幅
	int charaWidth, charaHeight;

	// グラフィックハンドル格納用配列
	int graphicHandle[12];

	// 横方向と縦方向のカウント数
	int xCount, yCount;

	// 添字用変数
	int imageX, imageY, result;
};
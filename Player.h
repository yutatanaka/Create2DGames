
#pragma once

#include "GameManager.h"
#include "Vec2f.h"
#include "Vec2i.h"
#include "Field.h"

class Player
{
private:

	// 入力処理メソッド
	void Input();

	// 重力処理メソッド
	void Gravity();

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

	// プレイヤーの現在、座標取得メソッド
	Vec2i GetMapPosition()const;

	// プレイヤーの下のマップデータを調べる
	int CheckUnder();

private:

	// 移動係数
	float move;

	// y方向のスピード
	float y_speed;

	// 重力
	float gravity;

	// 生きてるかどうかのフラグ
	bool isLive;

////////////////////////////////////

	// 歩く速度(定数)
	const int kSpeed = 3;

	// 1ピクセル分余白を持たせる(定数)
	const int kMargin = 1;

public:

	// キャラクターの座標
	Vec2i position;

	// キャラクターの大きさ
	Vec2f scale;

	// ジャンプしているかどうかのフラグ
	bool isJump;

	// 画像の幅
	int charaWidth, charaHeight;

	// グラフィックハンドル格納用配列
	int graphicHandle[12];

	// 横方向と縦方向のカウント数
	int xCount, yCount;

	// 添字用変数
	int imageX, imageY, result;
};
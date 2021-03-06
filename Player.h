
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

	// 画像アニメーションメソッド
	void Animation();

public: 

	// コンストラクタ
	Player();

	// 初期化処理メソッド
	void Initialize();

	// 更新処理メソッド
	void Update();

	// 描画処理メソッド
	void Draw();

	// 固定の床と当たっているときの処理メソッド
	void FieldIsHit(Field& field);

	// プレイヤーの現在、座標取得メソッド
	Vec2i GetMapPosition()const;

	// プレイヤーの下のマップデータを調べる
	int CheckUnder();

	// プレイヤーの左のマップデータを調べる
	int CheckRight();

	// プレイヤーの右のマップデータを調べる
	int CheckLeft();

private:

	// 移動係数
	float move;

	// 重力
	float gravity;

	// 右を向いているかどうかのフラグ
	bool isRight;

//////////////////////////////////////////////////////////

	// 歩く速度(定数)
	const int kSpeed = 5;

	// 1ピクセル分余白を持たせる(定数)
	const int kMargin = 1;

public:

	// キャラクターの座標
	Vec2i position;

	// キャラクターの大きさ
	Vec2f scale;

	// y方向のスピード
	float y_speed;

	// ジャンプしているかどうかのフラグ
	bool isJump;

	// 生きてるかどうかのフラグ
	bool isLive;

	// ゴール地点にいるかどうかのフラグ
	bool isGoal;

	// 初期ｘ座標(定数)
	const float kDefault_x = 65;

	// 初期ｙ座標(定数)
	const float kDefault_y = 770;

/////////////////////////////////////////

	// 画像の幅
	int charaWidth, charaHeight;

	// moveグラフィックハンドル格納用配列
	int moveGraphicHandle[MoveNumberElements];
	
	// waitグラフィックハンドル格納用配列
	int waitGraphicHandle[WaitNumberElements];

	// move用横方向のカウント数
	int move_xCount;
	
	// wait用横方向のカウント数
	int wait_xCount;

	// move添字用変数
	int moveImageX, moveResult;

	// wait添字用変数
	int waitImageX, waitResult;
};
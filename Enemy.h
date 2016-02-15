

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

	// ハチの移動処理
	void Bee1Move();
	void Bee2Move();

	// ネットの移動処理
	void Net1Move();
	void Net2Move();

	// ハチとの当たり判定
	void Bee1CheckHit();
	void Bee2CheckHit();

	// ネットとの当たり判定
	void Net1CheckHit();
	void Net2CheckHit();

public:

	// 速度
	int speed;

	// ハチの座標
	int bee1_x, bee1_y;
	int bee2_x, bee2_y;

	// ネットの座標
	int net1_x, net1_y;
	int net2_x, net2_y;

	// ハチの移動係数
	Vec2f bee_1Move;
	Vec2f bee_2Move;

	// ネットの移動係数
	Vec2f net_1Move;
	Vec2f net_2Move;

	// 距離
	Vec2i distance;
	
	// ハチの幅、高さ
	int beeWidth, beeHeight;			

	// あみの幅、高さ
	int netWidth, netHeight;

private:

	// 蜂のグラフィックハンドル格納用変数
	int beeGraphicHandle;

	// 虫取り網のグラフィックハンドル格納用変数
	int netGraphicHandle;

};
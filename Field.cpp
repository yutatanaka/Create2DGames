
#include <DxLib.h>
#include "GameManager.h"
#include "Vec2.h"
#include "Field.h"
#include "Player.h"

//当たり判定のあるボックスの数
const int hitBlockNumber = 256;

Field floorBox[hitBlockNumber];

// コンストラクタ
Field::Field() :
x(),
y(),
distance(),
blockGraphicHandle()
{
}

// 初期化メソッド
void Field::Initialize()
{

	// ブロック画像読み込み
	blockGraphicHandle = LoadGraph("res/background/field.png");

	// フィールドデータ2次元配列
	int fieldData[MAP_HEIGHT][MAP_WIDTH] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	memcpy(mapData, fieldData, sizeof(fieldData));

}

// 更新メソッド
void Field::Update()
{
	Draw();

	for (int i = 0; i < hitBlockNumber; ++i)
	{
		CheckHit(*gameManager.player);
	}
}


// 描画
void Field::Draw()
{
	for (y = 0; y< MAP_HEIGHT; ++y)
	{
		for (x = 0; x < MAP_WIDTH; ++x)
		{
			if (mapData[y][x] == 1)
			{
				//boxArray.pos.x = x_axis * MAP_SIZE;
				// 床の画像を読み込み
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, blockGraphicHandle, TRUE);
			}
		}
	}
}

// プレイヤーと床との当たり判定メソッド
void Field::CheckHit(Player& player)
{
	if (player.GetPosition().x + player.charaWidth > x &&	// 右端と左端
		player.GetPosition().x < x + boxWidth &&			// 左端
		player.GetPosition().y + player.charaHeight > y &&	// 下端と上端
		player.GetPosition().y < y + boxHeight)				// 上端
	{
		player.IsHit(*gameManager.field);
	}

}
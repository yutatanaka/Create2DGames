
#include <DxLib.h>
#include "GameManager.h"
#include "Vec2.h"
#include "Field.h"
#include "Player.h"

// コンストラクタ
Field::Field() :
x(),
y(),
width(64),
height(64),
blockGraphicHandle()
{
	// ブロック画像読み込み
	blockGraphicHandle = LoadGraph("res/background/field.png");
	
	// フィールドデータ2次元配列
	int fieldData[MAP_HEIGHT][MAP_WIDTH] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	memcpy(mapData, fieldData, sizeof(fieldData));

}

// デストラクタ
Field::~Field()
{
}

// 更新
void Field::Update()
{
	Draw();

	//当たり判定のあるボックスの数
	//const int hitBlockNumber = 256;

	//Field floorBox[hitBlockNumber];

	//for (int i = 0; i < hitBlockNumber; ++i)
	//{
	//	CheckHit(*gameManager.player);
	//}
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
				/*DrawBox(x_axis * MAP_SIZE, y_axis * MAP_SIZE,
					x_axis * MAP_SIZE + MAP_SIZE, y_axis * MAP_SIZE + MAP_SIZE,
					GetColor(0, 255, 0), TRUE);*/
			}
		}
	}
}

// プレイヤーと床との当たり判定メソッド
void Field::CheckHit(Player& player)
{
	if (player.GetPosition().x + player.width > x && // 右端と左端
		player.GetPosition().x < x + width &&	// 左端
		player.GetPosition().y + player.height > y && // 下端と上端
		player.GetPosition().y < y + height)	// 上端
	{

		//距離をはかる
		Vec2 distance;
		distance.x = player.GetPosition().x + player.width / 2 - (x + width / 2);
		distance.y = player.GetPosition().y + player.height / 2 - (y + height / 2);

		if (distance.x >= 0)distance.x *= -1;
		if (distance.y >= 0)distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (player.GetPosition().x < x)
			{
				player.position.x += x - (player.GetPosition().x + player.width);
			}
			else
			{
				player.position.x += x + width - player.GetPosition().x;
			}
		}
		else
		{
			if (player.GetPosition().y < y)
			{
				player.position.y += y - (player.GetPosition().y + player.height);
			}
			else
			{
				player.position.y += y + height - player.GetPosition().y;
			}
		}
	}

}
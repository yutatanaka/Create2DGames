
#include <DxLib.h>
#include <stdlib.h>
#include "GameManager.h"
#include "Vec2f.h"
#include "Field.h"
#include "Player.h"


// コンストラクタ
Field::Field() :
x(0),
y(0),
distance(0, 0),
boxWidth(64),
boxHeight(64)
{
}

// 初期化メソッド
void Field::Initialize()
{
	memset(fieldGraphicHandle, 0, sizeof(fieldGraphicHandle));

	// ブロック画像読み込み
	fieldGraphicHandle[0] = LoadGraph("res/floor/mapChip1Ground.png");
	fieldGraphicHandle[1] = LoadGraph("res/floor/mapChip2Grass.png");
	fieldGraphicHandle[2] = LoadGraph("res/floor/mapChip3Grass.png");
	fieldGraphicHandle[3] = LoadGraph("res/floor/mapChip4Grass.png");
	fieldGraphicHandle[4] = LoadGraph("res/object/dogHouse.png");

	// フィールドデータ2次元配列
	int fieldData[MAP_HEIGHT][MAP_WIDTH] =
	{
		
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 5 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0 },
		{ 0, 0, 2, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 2, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 2, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 0, 0, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0 },
		{ 0, 3, 4, 2, 3, 0, 0, 2, 3, 4, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 3, 4, 2, 1, 0 },
		{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },

	};

	memcpy(mapData, fieldData, sizeof(fieldData));

}

// 更新メソッド
void Field::Update()
{

	for (y = 0; y < MAP_HEIGHT; ++y)
	{
		for (x = 0; x < MAP_WIDTH; ++x)
		{
			if (mapData[y][x] == 1 || mapData[y][x] == 5)
			{
				FieldCheckHit(*(GameManager::GetInstance()->player), x * MAP_SIZE, y * MAP_SIZE);
			}
		}
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
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[0], TRUE);
			}
			else if (mapData[y][x] == 2)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[1], TRUE);
			}
			else if (mapData[y][x] == 3)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[2], TRUE);
			}
			else if (mapData[y][x] == 4)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[3], TRUE);
			}
			else if (mapData[y][x] == 5)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[4], TRUE);
			}
		}
	}
}

// プレイヤーと床との当たり判定を確認するメソッド
void Field::FieldCheckHit(Player& player, int x, int y)
{
	if (player.position.x + player.charaWidth > x && // 右端と左端
		player.position.x < x + boxWidth &&			 // 左端と右端
		player.position.y + player.charaHeight > y &&// 下端と上端
		player.position.y < y + boxHeight)			 // 上端と下端
	{
		player.FieldIsHit(*(GameManager::GetInstance()->field));
	}
}
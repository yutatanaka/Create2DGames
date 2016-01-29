
#include <DxLib.h>
#include "Vec2.h"
#include "Field.h"
#include "Player.h"

extern Field field;

// コンストラクタ
Field::Field() :
x_axis(0),
y_axis(0),
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

	CheckHit();

}

// 描画
void Field::Draw()
{
	for (y_axis = 0; y_axis < MAP_HEIGHT; y_axis++)
	{
		for (x_axis = 0; x_axis < MAP_WIDTH; x_axis++)
		{
			if (mapData[y_axis][x_axis] == 1)
			{

				// 床の画像を読み込み
				DrawGraph(x_axis * MAP_SIZE, y_axis * MAP_SIZE, blockGraphicHandle, TRUE);
				/*DrawBox(x_axis * MAP_SIZE, y_axis * MAP_SIZE,
					x_axis * MAP_SIZE + MAP_SIZE, y_axis * MAP_SIZE + MAP_SIZE,
					GetColor(0, 255, 0), TRUE);*/
			}
		}
	}
}

// プレイヤーと床との当たり判定メソッド
void Field::CheckHit()
{
}

// ブロックであるかどうか判定
bool Field::isBlock(Vec2 pos)
{
	int mapX = pos.x / 64;
	int mapY = pos.y / 64;

	if (mapData[mapY][mapX] == 1)
	{
		return true;
	}
	return false;
}
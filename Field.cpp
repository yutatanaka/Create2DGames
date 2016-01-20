
#include <DxLib.h>
#include "Vec2.h"
#include "Field.h"
#include "Player.h"

// コンストラクタ
Field::Field() :
x_axis(0),
y_axis(0),
y_plus(0),
y_minus(0),
x_plus(0),
x_minus(0),
height(64),
width(64)
{
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

	memcpy(MapData, fieldData, sizeof(fieldData));

}

// デストラクタ
Field::~Field()
{
}

// 更新
void Field::Update()
{
	Draw();

}

// 描画
void Field::Draw()
{
	for (y_axis = 0; y_axis < MAP_HEIGHT; y_axis++)
	{
		for (x_axis = 0; x_axis < MAP_WIDTH; x_axis++)
		{
			if (MapData[y_axis][x_axis] == 1)
			{
				DrawBox(x_axis * MAP_SIZE, y_axis * MAP_SIZE,
					x_axis * MAP_SIZE + MAP_SIZE, y_axis * MAP_SIZE + MAP_SIZE,
					GetColor(0, 255, 0), TRUE);
			}
		}
	}
}

// 当たり判定
void Field::CollisionDetection(Vec2 pos)
{
	if (MapData[y_axis][x_axis] == 1)
	{
		Vec2 x = pos / 100;
		Vec2 y = pos / 100;
	}
}
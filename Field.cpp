
#include <DxLib.h>
#include "Field.h"
#include "Player.h"

// �R���X�g���N�^
Field::Field() :
x_axis(0),
y_axis(0),
y_plus(0),
y_minus(0),
x_plus(0),
x_minus(0),
height(0),
width(0)
{
	int fieldData[MAP_HEIGHT][MAP_WIDTH] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	memcpy(MapData, fieldData, sizeof(fieldData));

}

// �f�X�g���N�^
Field::~Field()
{
}

// �X�V
void Field::Update()
{
	Draw();
}

// �`��
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

// �����蔻��
void Field::CollisionDetection(Vec2 x, Vec2 y)
{

	// �}�b�v�`�b�v�̒��S�_
	int centerPoint = height / 2 + width / 2;


	if (MapData[y_axis][x_axis] == 1)
	{
		y_minus = centerPoint + (height / 2);

		y_plus = centerPoint - (height / 2);

	}
}
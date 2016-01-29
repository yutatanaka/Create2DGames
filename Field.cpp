
#include <DxLib.h>
#include "Vec2.h"
#include "Field.h"
#include "Player.h"

extern Field field;

// �R���X�g���N�^
Field::Field() :
x_axis(0),
y_axis(0),
width(64),
height(64),
blockGraphicHandle()
{
	// �u���b�N�摜�ǂݍ���
	blockGraphicHandle = LoadGraph("res/background/field.png");
	
	// �t�B�[���h�f�[�^2�����z��
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

// �f�X�g���N�^
Field::~Field()
{
}

// �X�V
void Field::Update()
{
	Draw();

	CheckHit();

}

// �`��
void Field::Draw()
{
	for (y_axis = 0; y_axis < MAP_HEIGHT; y_axis++)
	{
		for (x_axis = 0; x_axis < MAP_WIDTH; x_axis++)
		{
			if (mapData[y_axis][x_axis] == 1)
			{

				// ���̉摜��ǂݍ���
				DrawGraph(x_axis * MAP_SIZE, y_axis * MAP_SIZE, blockGraphicHandle, TRUE);
				/*DrawBox(x_axis * MAP_SIZE, y_axis * MAP_SIZE,
					x_axis * MAP_SIZE + MAP_SIZE, y_axis * MAP_SIZE + MAP_SIZE,
					GetColor(0, 255, 0), TRUE);*/
			}
		}
	}
}

// �v���C���[�Ə��Ƃ̓����蔻�胁�\�b�h
void Field::CheckHit()
{
}

// �u���b�N�ł��邩�ǂ�������
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
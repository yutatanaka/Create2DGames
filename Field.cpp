
#include <DxLib.h>
#include "GameManager.h"
#include "Vec2f.h"
#include "Field.h"
#include "Player.h"


// �R���X�g���N�^
Field::Field() :
x(0),
y(0),
distance(0, 0),
boxWidth(64),
boxHeight(64)
{
	fieldGraphicHandle[fieldNumberElements] = { 0 };
}

// ���������\�b�h
void Field::Initialize()
{
	// �u���b�N�摜�ǂݍ���
	fieldGraphicHandle[0] = LoadGraph("res/floor/mapChip1Ground.png");
	fieldGraphicHandle[1] = LoadGraph("res/floor/mapChip2Grass.png");
	fieldGraphicHandle[2] = LoadGraph("res/floor/mapChip3Grass.png");
	fieldGraphicHandle[3] = LoadGraph("res/floor/mapChip4Grass.png");
	fieldGraphicHandle[4] = LoadGraph("res/floor/mapChip5Soil.png");
	fieldGraphicHandle[5] = LoadGraph("res/floor/mapChip6Soil.png");
	fieldGraphicHandle[6] = LoadGraph("res/floor/mapChip7WallLeft.png");
	fieldGraphicHandle[7] = LoadGraph("res/floor/mapChip8WallLeft.png");
	fieldGraphicHandle[8] = LoadGraph("res/floor/mapChip9WallRight.png");
	fieldGraphicHandle[9] = LoadGraph("res/floor/mapChip10WallRight.png");


	// �t�B�[���h�f�[�^2�����z��
	int fieldData[MAP_HEIGHT][MAP_WIDTH] =
	{
		
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1 },
		{ 10, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 7, 1 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1 },
		{ 10, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1 },
		{ 10, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1 },
		{ 10, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 8, 1 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 8, 1 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1 },
		{ 10, 0, 4, 2, 3, 0, 0, 2, 3, 4, 0, 7, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1 },
		{ 10, 1, 1, 1, 1, 9, 7, 1, 1, 1, 9, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },

		

	};

	memcpy(mapData, fieldData, sizeof(fieldData));

}

// �X�V���\�b�h
void Field::Update()
{
	Draw();

	for (y = 0; y < MAP_HEIGHT; ++y)
	{
		for (x = 0; x < MAP_WIDTH; ++x)
		{
			if (mapData[y][x] == 1)
			{
				CheckHit(*(GameManager::GetInstance()->player), x * MAP_SIZE, y * MAP_SIZE);
			}
		}
	}

}

// �`��
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
			else if (mapData[y][x] == 6)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[5], TRUE);
			}
			else if (mapData[y][x] == 7)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[6], TRUE);
			}
			else if (mapData[y][x] == 8)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[7], TRUE);
			}
			else if (mapData[y][x] == 9)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[8], TRUE);
			}
			else if (mapData[y][x] == 10)
			{
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, fieldGraphicHandle[9], TRUE);
			}
		}
	}
}

// �v���C���[�Ə��Ƃ̓����蔻����m�F���郁�\�b�h
void Field::CheckHit(Player& player, int x, int y)
{
	if (player.position.x + player.charaWidth > x && // �E�[�ƍ��[
		player.position.x < x + boxWidth &&			 // ���[�ƉE�[
		player.position.y + player.charaHeight > y &&// ���[�Ə�[
		player.position.y < y + boxHeight)			 // ��[�Ɖ��[
	{
		player.IsHit(*(GameManager::GetInstance()->field));
	}
}
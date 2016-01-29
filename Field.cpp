
#include <DxLib.h>
#include "GameManager.h"
#include "Vec2.h"
#include "Field.h"
#include "Player.h"

// �R���X�g���N�^
Field::Field() :
x(),
y(),
distance(),
blockGraphicHandle()
{
}

// ���������\�b�h
void Field::Initialize()
{

	// �u���b�N�摜�ǂݍ���
	blockGraphicHandle = LoadGraph("res/background/field.png");

	// �t�B�[���h�f�[�^2�����z��
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

// �X�V���\�b�h
void Field::Update()
{
	Draw();

	//�����蔻��̂���{�b�N�X�̐�
	//const int hitBlockNumber = 256;

	//Field floorBox[hitBlockNumber];

	//for (int i = 0; i < hitBlockNumber; ++i)
	//{
	//	CheckHit(*gameManager.player);
	//}
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
				//boxArray.pos.x = x_axis * MAP_SIZE;
				// ���̉摜��ǂݍ���
				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, blockGraphicHandle, TRUE);
			}
		}
	}
}

// �v���C���[�Ə��Ƃ̓����蔻�胁�\�b�h
void Field::CheckHit(Player& player)
{
	if (player.GetPosition().x + player.width > x &&	// �E�[�ƍ��[
		player.GetPosition().x < x + kWidth &&			// ���[
		player.GetPosition().y + player.height > y &&	// ���[�Ə�[
		player.GetPosition().y < y + kHeight)			// ��[
	{

		distance.x = player.GetPosition().x + player.width / 2 - (x + kWidth / 2);
		distance.y = player.GetPosition().y + player.height / 2 - (y + kHeight / 2);

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
				player.position.x += x + kWidth - player.GetPosition().x;
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
				player.position.y += y + kHeight - player.GetPosition().y;
			}
		}
	}

}
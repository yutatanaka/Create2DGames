
#include "MoveFloor.h"
#include "Player.h"

// �R���X�g���N�^
MoveFloor::MoveFloor() :
x(1280),
y(64),
move(0, 4),
distance(0, 0),
width(64),
height(64),
moveFloorGraphicHandle(0)
{
}

// �f�X�g���N�^
MoveFloor::~MoveFloor()
{
}

// �������������\�b�h
void MoveFloor::Initialize()
{
	moveFloorGraphicHandle = LoadGraph("res/floor/moveFloor.png");
}

// �X�V�������\�b�h
void MoveFloor::Update()
{

	MoveFloorCheckHit();

	Move();

}

// �`�揈�����\�b�h
void MoveFloor::Draw()
{
	//DrawBox(x, y, x + width, y + height, GetColor(0, 255, 255), TRUE);
	DrawGraph(x, y , moveFloorGraphicHandle, TRUE);
}

// �ړ��������\�b�h
void MoveFloor::Move()
{
	y += move.y;
	if (y < 64 || y > 320)
	{
		move.y = -move.y;
	}
}


// �v���C���[�Ɠ������Ƃ̓����蔻����m�F���郁�\�b�h
void MoveFloor::MoveFloorCheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > x && // �E�[�ƍ��[
		GameManager::GetInstance()->player->position.x < x + width &&			  // ���[�ƉE�[
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > y &&// ���[�Ə�[
		GameManager::GetInstance()->player->position.y < y + height)			  // ��[�Ɖ��[
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (x + width / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (y + height / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <x)
			{
				GameManager::GetInstance()->player->position.x += x - (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth);
			}
			else
			{
				GameManager::GetInstance()->player->position.x += x + width - GameManager::GetInstance()->player->position.x;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < y)
			{
				GameManager::GetInstance()->player->position.y += y - (GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight);
				GameManager::GetInstance()->player->y_speed = 0;
			}
			else
			{
				GameManager::GetInstance()->player->position.y += y + height - GameManager::GetInstance()->player->position.y;
				GameManager::GetInstance()->player->y_speed = 0;
			}
		}
	}
}
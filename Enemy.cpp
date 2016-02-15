
#include "Enemy.h"
#include "Player.h"

// �R���X�g���N�^
Enemy::Enemy() :
bee_x(1280),
bee_y(64),
move(0, 4),
distance(0, 0),
width(64),
height(64),
beeGraphicHandle(0),
butterflyNetGraphicHandle(0)
{
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �������������\�b�h
void Enemy::Initialize()
{
	beeGraphicHandle = LoadGraph("res/enemy");
}

// �X�V�������\�b�h
void Enemy::Update()
{

	BeeCheckHit();

	Move();

}

// �`�揈�����\�b�h
void Enemy::Draw()
{
	//DrawBox(x, y, x + width, y + height, GetColor(0, 255, 255), TRUE);
	DrawGraph(bee_x, bee_y, beeGraphicHandle, TRUE);
}

// �ړ��������\�b�h
void Enemy::Move()
{
	bee_y += move.y;
	if (bee_y < 64 || bee_y > 320)
	{
		move.y = -move.y;
	}
}


// �v���C���[�Ɠ������Ƃ̓����蔻����m�F���郁�\�b�h
void Enemy::BeeCheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > bee_x && // �E�[�ƍ��[
		GameManager::GetInstance()->player->position.x < bee_x + width &&			  // ���[�ƉE�[
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > bee_y &&// ���[�Ə�[
		GameManager::GetInstance()->player->position.y < bee_y + height)			  // ��[�Ɖ��[
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (bee_x + width / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (bee_y + height / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <bee_x)
			{
				GameManager::GetInstance()->player->position.x += bee_x - (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth);
			}
			else
			{
				GameManager::GetInstance()->player->position.x += bee_x + width - GameManager::GetInstance()->player->position.x;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < bee_y)
			{
				GameManager::GetInstance()->player->position.y += bee_y - (GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight);
				GameManager::GetInstance()->player->y_speed = 0;
			}
			else
			{
				GameManager::GetInstance()->player->position.y += bee_y + height - GameManager::GetInstance()->player->position.y;
				GameManager::GetInstance()->player->y_speed = 0;
			}
		}
	}
}
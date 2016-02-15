
#include "Enemy.h"
#include "Player.h"

// �R���X�g���N�^
Enemy::Enemy() :
bee1_x(1290),
bee1_y(64),
bee2_x(0),
bee2_y(0),
net1_x(0),
net1_y(0),
net2_x(0),
net2_y(0),
bee_1Move(0, 4),
bee_2Move(0, 4),
net_1Move(4, 0),
net_2Move(4, 0),
distance(0, 0),
beeWidth(40),
beeHeight(40),
netWidth(50),
netHeight(50),
beeGraphicHandle(0),
netGraphicHandle(0)
{
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �������������\�b�h
void Enemy::Initialize()
{
	beeGraphicHandle = LoadGraph("res/enemy/bee.png");
}

// �X�V�������\�b�h
void Enemy::Update()
{
	Bee1Move();

	Bee1CheckHit();

	Bee2Move();
	Bee2CheckHit();

	Net1Move();
	Net1CheckHit();

	Net2Move();
	Net2CheckHit();
	
	

}

// �`�揈�����\�b�h
void Enemy::Draw()
{
	DrawGraph(bee1_x, bee1_y, beeGraphicHandle, TRUE);
}

// �n�`�̈ړ��������\�b�h
void Enemy::Bee1Move()
{
	bee1_y += bee_1Move.y;
	if (bee1_y < 64 || bee1_y > 320)
	{
		bee_1Move.y = -bee_1Move.y;
	}
}

// �n�`�ړ��������\�b�h
void Enemy::Bee2Move()
{
	bee2_y += bee_2Move.y;
	if (bee2_y < 64 || bee2_y > 320)
	{
		bee_2Move.y = -bee_2Move.y;
	}
}

// �l�b�g�̈ړ��������\�b�h
void Enemy::Net1Move()
{
	net1_y += net_1Move.y;
	if (net1_y < 64 || net1_y > 320)
	{
		net_1Move.y = -net_1Move.y;
	}
}

// �l�b�g�̈ړ��������\�b�h
void Enemy::Net2Move()
{
	net2_y += net_2Move.y;
	if (net2_y < 64 || net2_y > 320)
	{
		net_2Move.y = -net_2Move.y;
	}
}

// �v���C���[�Ɠ������Ƃ̓����蔻����m�F���郁�\�b�h
void Enemy::Bee1CheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > bee1_x && // �E�[�ƍ��[
		GameManager::GetInstance()->player->position.x < bee1_x + beeWidth &&			  // ���[�ƉE�[
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > bee1_y &&// ���[�Ə�[
		GameManager::GetInstance()->player->position.y < bee1_y + beeHeight)			  // ��[�Ɖ��[
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (bee1_x + beeWidth / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (bee1_y + beeHeight / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <bee1_x)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < bee1_y)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
	}
}

void Enemy::Bee2CheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > bee2_x && // �E�[�ƍ��[
		GameManager::GetInstance()->player->position.x < bee2_x + beeWidth &&			  // ���[�ƉE�[
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > bee2_y &&// ���[�Ə�[
		GameManager::GetInstance()->player->position.y < bee2_y + beeHeight)			  // ��[�Ɖ��[
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (bee2_x + beeWidth / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (bee2_y + beeHeight / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <bee2_x)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < bee2_y)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
	}
}

void Enemy::Net1CheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > net1_x && // �E�[�ƍ��[
		GameManager::GetInstance()->player->position.x < net1_x + beeWidth &&			  // ���[�ƉE�[
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > net1_y &&// ���[�Ə�[
		GameManager::GetInstance()->player->position.y < net1_y + beeHeight)			  // ��[�Ɖ��[
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (net1_x + beeWidth / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (net1_y + beeHeight / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <net1_x)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < net1_y)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
	}
}

void Enemy::Net2CheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > net2_x && // �E�[�ƍ��[
		GameManager::GetInstance()->player->position.x < net2_x + beeWidth &&			  // ���[�ƉE�[
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > net2_y &&// ���[�Ə�[
		GameManager::GetInstance()->player->position.y < net2_y + beeHeight)			  // ��[�Ɖ��[
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (net2_x + beeWidth / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (net2_y + beeHeight / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <net2_x)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < net2_y)
			{
				GameManager::GetInstance()->player->isLive = false;
			}
			else
			{
				GameManager::GetInstance()->player->isLive = false;
			}
		}
	}
}
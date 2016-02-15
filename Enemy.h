

#pragma once

#include "GameManager.h"
#include "Vec2f.h"
#include "Vec2i.h"
#include "Player.h"

class Enemy
{
public:

	// �R���X�g���N�^
	Enemy();

	// �f�X�g���N�^
	~Enemy();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// �n�`�̈ړ�����
	void Bee1Move();
	void Bee2Move();

	// �l�b�g�̈ړ�����
	void Net1Move();
	void Net2Move();

	// �n�`�Ƃ̓����蔻��
	void Bee1CheckHit();
	void Bee2CheckHit();

	// �l�b�g�Ƃ̓����蔻��
	void Net1CheckHit();
	void Net2CheckHit();

public:

	// ���x
	int speed;

	// �n�`�̍��W
	int bee1_x, bee1_y;
	int bee2_x, bee2_y;

	// �l�b�g�̍��W
	int net1_x, net1_y;
	int net2_x, net2_y;

	// �n�`�̈ړ��W��
	Vec2f bee_1Move;
	Vec2f bee_2Move;

	// �l�b�g�̈ړ��W��
	Vec2f net_1Move;
	Vec2f net_2Move;

	// ����
	Vec2i distance;
	
	// �n�`�̕��A����
	int beeWidth, beeHeight;			

	// ���݂̕��A����
	int netWidth, netHeight;

private:

	// �I�̃O���t�B�b�N�n���h���i�[�p�ϐ�
	int beeGraphicHandle;

	// �����Ԃ̃O���t�B�b�N�n���h���i�[�p�ϐ�
	int netGraphicHandle;

};
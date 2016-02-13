

#pragma once

#include "GameManager.h"
#include "Vec2f.h"
#include "Player.h"

class MoveFloor
{
public:

	// �R���X�g���N�^
	MoveFloor();

	// �f�X�g���N�^
	~MoveFloor();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// �ړ�����
	void Move();

	// �����蔻��
	// true..�������Ă��� false...�������Ă��Ȃ�
	void MoveFloorCheckHit(Player& player, int x, int y);


public:

	// ���̃|�W�V����
	Vec2f pos;			

	// �ړ��W��
	Vec2f move;				

	// �X�s�[�h
	float speed;			

	// ���A����
	int width, height;		
	
	// �ŏ����W
	Vec2f _min;

	// �ő���W
	Vec2f _max;				

	// �F
	int color;

};

extern MoveFloor moveFloor;
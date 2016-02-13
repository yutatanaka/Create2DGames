

#pragma once

#include "GameManager.h"
#include "Vec2f.h"
#include "Vec2i.h"
#include "Player.h"

class MoveFloor
{
public:

	// �R���X�g���N�^
	MoveFloor();

	// �f�X�g���N�^
	~MoveFloor();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// �ړ�����
	void Move();

	// �����蔻��
	void MoveFloorCheckHit();


public:

	// ���W
	int x, y;

	// �ړ��W��
	Vec2f move;				

	// ����
	Vec2i distance;
	
	// ���A����
	int width, height;			

private:

	// �������̃O���t�B�b�N�n���h���i�[�p�ϐ�
	int moveFloorGraphicHandle;

};
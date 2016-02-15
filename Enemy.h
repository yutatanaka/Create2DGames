

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

	// �ړ�����
	void Move();

	// �����蔻��
	void BeeCheckHit();


public:

	// ���W
	int bee_x, bee_y;

	// �ړ��W��
	Vec2f move;				

	// ����
	Vec2i distance;
	
	// ���A����
	int width, height;			

private:

	// �I�̃O���t�B�b�N�n���h���i�[�p�ϐ�
	int beeGraphicHandle;

	// �����Ԃ̃O���t�B�b�N�n���h���i�[�p�ϐ�
	int butterflyNetGraphicHandle;

};
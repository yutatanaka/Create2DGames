
#pragma once

#include "GameManager.h"
#include "Vec2.h"
#include "Key.h"
#include "Field.h"

class Player
{
private:

	// ���͏������\�b�h
	void Input();

	// �d�͏������\�b�h
	void Gravity();

	// �ړ����䃁�\�b�h
	void MovementControl();

public: 

	// �R���X�g���N�^
	Player();

	// �������������\�b�h
	void Initialize();

	// �X�V�������\�b�h
	void Update();

	// �`�揈�����\�b�h
	void Draw();

	// �������Ă���Ƃ��̏������\�b�h
	void IsHit(Field& field);

	// �L�����N�^�[�̌��݁A���W�擾���\�b�h
	Vec2 GetPosition()const{ return position; }

private:

	// �ړ��W��
	float move;

	// y�����̃X�s�[�h
	float y_speed;

	// �d��
	float gravity;

	// �W�����v���Ă��邩�ǂ����̃t���O
	bool isJump;

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

////////////////////////////////////

	// �������x(�萔)
	const int kSpeed = 3;

	// 1�s�N�Z�����]������������(�萔)
	const int kMargin = 1;

public:

	// �L�����N�^�[�̍��W
	Vec2 position;

	// �L�����N�^�[�̑傫��
	Vec2 scale;

	// �摜�̕�
	int charaWidth, charaHeight;

	// �O���t�B�b�N�n���h���i�[�p�z��
	int graphicHandle[12];

	// �������Əc�����̃J�E���g��
	int xCount, yCount;

	// �Y���p�ϐ�
	int imageX, imageY, result;
};
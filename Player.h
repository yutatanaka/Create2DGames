
#pragma once

#include "Vec2.h"

class Player
{
private:

	// �ړ�����
	void Input();

	// �d�͏���
	void Gravity();

public: 

	// �R���X�g���N�^
	Player();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// �L�����N�^�[�̌��݁A���W�擾
	Vec2 GetPosition()const{ return position; }

private:


	// �ړ��W��
	float move;

	// �W�����v��
	float jumpPower;

	// �W�����v���Ă��邩�ǂ����̃t���O
	bool isJump;

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

////////////////////////////////////

	// �������x(�萔)
	const int kSpeed = 3;

public:

	// �L�����N�^�[�̍��W
	Vec2 position;

	// �L�����N�^�[�̑傫��
	Vec2 scale;

	// �摜�̕�
	int width, height;

	// �O���t�B�b�N�n���h���i�[�p�z��
	int graphicHandle[12];

	// �e�X�g�p�n���h��
	//int graphicHandle;

	// �������Əc�����̃J�E���g��
	int xCount, yCount;

	// �Y���p�ϐ�
	int imageX, imageY, result;
};



#pragma once

#include "Vec2.h"

class Player
{
public:
	
	Player();

	void Update();

private:

	// �ړ�����
	void Input();

	// �`�揈��
	void Draw();

public: 

	// �L�����N�^�[�̍��W
	Vec2 position;

private:

	// �L�����N�^�[�̑傫��
	Vec2 scale;

	// �摜�̕�
	int width, height;

	// �O���t�B�b�N�n���h���i�[�p�z��
	int graphicHandle[12];

	// �������Əc�����̃J�E���g��
	int xCount, yCount;

	// �Y���p�ϐ�
	int imageX, imageY, result;

	// �ړ��W��
	float move;

	// �W�����v��
	int jumpPower;

	// �d��
	int gravity;

	// �W�����v���Ă��邩�ǂ����̃t���O
	bool isJump;

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

////////////////////////////////////

	// �������x(�萔)
	const int kSpeed = 3;
};

// �L�[�擾�p�z��
extern char key[256];
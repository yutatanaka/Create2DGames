
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

private:

	// �L�����N�^�[�̍��W
	Vec2 position;

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

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

	// �ړ��W��
	float move;

	// �W�����v��
	int jumpPower;

	// �d��
	int gravity;

////////////////////////////////////

	// �������x(�萔)
	const int kSpeed = 3;
};

// �L�[�擾�p�z��
extern char key[256];
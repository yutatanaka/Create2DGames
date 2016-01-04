
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
	Vec2f position;

	// �摜�̕�
	int width, height;

	// �O���t�B�b�N�n���h���i�[�p�z��
	int graphicHandle[12];

	// �ړ��W��
	float move;

	// �������Əc�����̃J�E���g��
	int xCount, yCount;

	// �Y���p�ϐ�
	int imageX, imageY, result;

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

////////////////////////////////////

	// �������x(�萔)
	const int kSpeed = 3;
};

// �L�[�擾�p�z��
extern char key[256];
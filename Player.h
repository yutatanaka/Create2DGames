
#pragma once

class Player
{
public:
	Player();
	void All();

private:

	// �ړ�����
	void Move();

	// �`�揈��
	void Draw();

private:

	// x���W, y���W
	float x, y;

	// �摜��
	int width, height;

	// �O���t�B�b�N�n���h���i�[�p�z��
	int graphicHandle[12];

	// �ړ��W��
	float move;

	// �������Əc�����̃J�E���g��
	int xCount, yCount;

	// �Y���p�ϐ�
	int ix, iy, result;

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

};

#pragma once

#include <math.h>
#include "DxLib.h"

class Fps
{

public:

	// �R���X�g���N�^
	Fps();

	// �f�X�g���N�^
	~Fps();

	// �X�V���\�b�h
	bool Update();

	// �`�惁�\�b�h
	void Draw();

	// �����������ԓ����v�����郁�\�b�h
	void Wait();

public:

	// ����J�n����
	int startTime;

	// �J�E���^
	int count;

	// FPS
	float fps;

//////////////////////////////////////////

	// ���ς����T���v����(�萔)
	static const int N = 60;

	// �ݒ肵��FPS(�萔)
	static const int FPS = 60;
};
	
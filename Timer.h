
#pragma once

class Timer
{
public:

	// �R���X�g���N�^
	Timer();

	// �f�X�g���N�^
	~Timer();

	// �X�V�������\�b�h
	void Update();

	// �`�揈�����\�b�h
	void Draw();

	// ���l��`�揈�����郁�\�b�h
	void DrawNum(int x, int y, int Num);


public:

	// �����̐F�R�[�h
	int color;

	// �J�E���g�J�n����
	int startTime;

	// �O�t���[���̌o�ߎ���
	int oldTime;

	// ���݂̌o�ߎ���
	int nowTime;
};

#define _CRT_SECURE_NO_WARNIGS

#include <stdlib.h>
#include <stdio.h>
#include "DxLib.h"
#include "Timer.h"
#include "GameManager.h"

// �R���X�g���N�^
Timer::Timer() :
color(GetColor(0, 0, 0)),
startTime(GetNowCount()),
oldTime(0),
nowTime(0)
{	
}

// �f�X�g���N�^
Timer::~Timer()
{
}

// �X�V����
void Timer::Update()
{
	// 30�b�o�܂Ōv������
	while (ProcessMessage() == 0 && nowTime < 30000)
	{
		// ����̌o�߃^�C�����擾
		nowTime = GetNowCount() - startTime;

		// �O��̎c��b���ƍ���̎c��b����������ꍇ�͎c��b�����X�V
		if (nowTime / 1000 != oldTime / 1000)
		{
			DrawNum(100, 80, 30 - nowTime / 1000);

			// ����̃^�C����ۑ�
			oldTime = nowTime;
		}
	}
}

// �`�揈��
void Timer::Draw()
{
	DrawString(Width / 2, 50, "TIME:", color);
	DrawNum(100, 80, 30);
}

// ���l����ʂɕ\�����郁�\�b�h
void Timer::DrawNum(int x, int y, int Num)
{
	char StrBuf[80];

	// ���l��10�i��������ɕϊ�
	itoa(Num, StrBuf, 10);

	// ��ʂɕ`��
	DrawBox(x, y, x + strlen(StrBuf) * 20, y + 20, 0, TRUE);
	DrawString(x, y, StrBuf, color);
}


#include "Fps.h"
#include"gamemanager.h"

Fps fps;

// �R���X�g���N�^
Fps::Fps() :
startTime(0),
count(0),
fps(0)
{
}

// �f�X�g���N�^
Fps::~Fps()
{

}

// �X�V���\�b�h
bool Fps::Update()
{
	if (count == 0)				// 1�t���[���ڂȂ玞�����L������
	{
		startTime = GetNowCount();
	}
	if (count == kAverage)		// 60�t���[���ڂȂ畽�ς��v�Z����
	{
		int time = GetNowCount();
		fps = 1000.f / ((time - startTime) / (float)kAverage);
		count = 0;
		startTime = time;
	}
	count++;
	return true;
}

// �`�惁�\�b�h
void Fps::Draw()
{
	DrawFormatString(Window::Width / 2, 20, GetColor(255, 0, 0), "fps:%.1f", fps);

}

// �����������ԓ����v�����郁�\�b�h
void Fps::Wait()
{
	int tookTime = GetNowCount() - startTime;		// ������������
	int waitTime = count * 1000 / kFPS - tookTime;	// �҂ׂ�����
	if (waitTime > 0)
	{
		Sleep(waitTime);	// �ҋ@
	}
}

#include "Fps.h"
#include"gamemanager.h"

Fps fps;

// コンストラクタ
Fps::Fps() :
startTime(0),
count(0),
fps(0)
{
}

// デストラクタ
Fps::~Fps()
{

}

// 更新メソッド
bool Fps::Update()
{
	if (count == 0)				// 1フレーム目なら時刻を記憶する
	{
		startTime = GetNowCount();
	}
	if (count == kAverage)		// 60フレーム目なら平均を計算する
	{
		int time = GetNowCount();
		fps = 1000.f / ((time - startTime) / (float)kAverage);
		count = 0;
		startTime = time;
	}
	count++;
	return true;
}

// 描画メソッド
void Fps::Draw()
{
	DrawFormatString(Window::Width / 2, 20, GetColor(255, 0, 0), "fps:%.1f", fps);

}

// かかった時間等を計測するメソッド
void Fps::Wait()
{
	int tookTime = GetNowCount() - startTime;		// かかった時間
	int waitTime = count * 1000 / kFPS - tookTime;	// 待つべき時間
	if (waitTime > 0)
	{
		Sleep(waitTime);	// 待機
	}
}
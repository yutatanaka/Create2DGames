
#pragma once

#include <math.h>
#include "DxLib.h"

class Fps
{

public:

	// コンストラクタ
	Fps();

	// デストラクタ
	~Fps();

	// 更新メソッド
	bool Update();

	// 描画メソッド
	void Draw();

	// かかった時間等を計測するメソッド
	void Wait();

public:

	// 測定開始時刻
	int startTime;

	// カウンタ
	int count;

	// FPS
	float fps;

//////////////////////////////////////////

	// 平均を取るサンプル数(定数)
	static const int N = 60;

	// 設定したFPS(定数)
	static const int FPS = 60;
};
	

#define _CRT_SECURE_NO_WARNIGS

#include <stdlib.h>
#include <stdio.h>
#include "DxLib.h"
#include "Timer.h"
#include "GameManager.h"

// コンストラクタ
Timer::Timer() :
color(GetColor(0, 0, 0)),
startTime(GetNowCount()),
oldTime(0),
nowTime(0)
{	
}

// デストラクタ
Timer::~Timer()
{
}

// 更新処理
void Timer::Update()
{
	// 30秒経つまで計測処理
	while (ProcessMessage() == 0 && nowTime < 30000)
	{
		// 今回の経過タイムを取得
		nowTime = GetNowCount() - startTime;

		// 前回の残り秒数と今回の残り秒数が違った場合は残り秒数を更新
		if (nowTime / 1000 != oldTime / 1000)
		{
			DrawNum(100, 80, 30 - nowTime / 1000);

			// 今回のタイムを保存
			oldTime = nowTime;
		}
	}
}

// 描画処理
void Timer::Draw()
{
	DrawString(Width / 2, 50, "TIME:", color);
	DrawNum(100, 80, 30);
}

// 数値を画面に表示するメソッド
void Timer::DrawNum(int x, int y, int Num)
{
	char StrBuf[80];

	// 数値を10進数文字列に変換
	itoa(Num, StrBuf, 10);

	// 画面に描画
	DrawBox(x, y, x + strlen(StrBuf) * 20, y + 20, 0, TRUE);
	DrawString(x, y, StrBuf, color);
}

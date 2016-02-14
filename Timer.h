
#pragma once

class Timer
{
public:

	// コンストラクタ
	Timer();

	// デストラクタ
	~Timer();

	// 更新処理メソッド
	void Update();

	// 描画処理メソッド
	void Draw();

	// 数値を描画処理するメソッド
	void DrawNum(int x, int y, int Num);


public:

	// 文字の色コード
	int color;

	// カウント開始時間
	int startTime;

	// 前フレームの経過時間
	int oldTime;

	// 現在の経過時間
	int nowTime;
};

#pragma once

class Player
{
public:
	Player();
	void All();

private:

	// 移動処理
	void Move();

	// 描画処理
	void Draw();

private:

	// x座標, y座標
	float x, y;

	// 画像幅
	int width, height;

	// グラフィックハンドル格納用配列
	int graphicHandle[12];

	// 移動係数
	float move;

	// 横方向と縦方向のカウント数
	int xCount, yCount;

	// 添字用変数
	int ix, iy, result;

	// 生きてるかどうかのフラグ
	bool isLive;

};

#pragma once

#include "Player.h"

enum Window
{
	Width = 1024,
	Height = 768,
	ColorBit = 32
};

class GameManager
{
public:

	// コンストラクタ
	GameManager();

	// デストラクタ
	~GameManager();

	// 初期化メソッド
	void Initialize();

	// 30フレームに設定
	int fps;

};

extern GameManager gameManager;

#pragma once

#include "Player.h"

enum Window
{
	Width = 1280,
	Height = 960,
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

	//Player *player;

};

extern GameManager gameManager;
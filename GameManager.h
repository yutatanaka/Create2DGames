
#pragma once

#include "Player.h"

enum Window
{
	Width = 1200,
	Height = 950,
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
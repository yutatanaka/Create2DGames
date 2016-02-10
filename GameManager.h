
#pragma once

#include "SceneManager.h"

#define MoveNumberElements 6
#define WaitNumberElements 4

class Player;
class Field;

enum Window
{
	Width = 1600,
	Height = 960,
	ColorBit = 32
};

class GameManager
{
private :

	// コンストラクタ
	GameManager();

public:

	static GameManager* instance ;

	// シングルトン
	static GameManager* GetInstance()
	{
		
		if (nullptr == instance)
		{
			instance = new GameManager();
		}
		return instance;
	}

	static GameManager* DeleteInstance()
	{
		delete instance;

		return instance;
	}

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

public:

	// デストラクタ
	~GameManager();

	// 各インスタンスを生成

	Player *player;

	Field *field;

};


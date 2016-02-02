
#pragma once

class Player;
class Field;
class BackGround;

enum Window
{
	Width = 1024,
	Height = 768,
	ColorBit = 32
};

class GameManager
{
private :

	// コンストラクタ
	GameManager();

public:
	// シングルトン
	static GameManager& GetInstance()
	{
		static GameManager instance;
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

	Player *player;
	Field *field;
	BackGround *backGround;
};


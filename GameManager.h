
#pragma once

class Player;
class Field;

enum Window
{
	Width = 1024,
	Height = 768,
	ColorBit = 32
};

class GameManager
{
public:
	// シングルトン
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	// 初期化メソッド
	void Initialize();

	void Update();

	void Draw();
private:

	// コンストラクタ
	GameManager();

	// デストラクタ
	~GameManager();

	Player *player;
	Field *field;
};


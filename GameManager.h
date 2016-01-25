
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
public:
	// シングルトン
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

private:

	// コンストラクタ
	GameManager();

	// デストラクタ
	~GameManager();

	Player *player;
	Field *field;
	BackGround *backGround;
};


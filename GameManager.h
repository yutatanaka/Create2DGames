
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
	// �V���O���g��
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	// ���������\�b�h
	void Initialize();

	void Update();

	void Draw();
private:

	// �R���X�g���N�^
	GameManager();

	// �f�X�g���N�^
	~GameManager();

	Player *player;
	Field *field;
};


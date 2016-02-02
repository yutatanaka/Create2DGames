
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

	// �R���X�g���N�^
	GameManager();

public:
	// �V���O���g��
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

public:


	// �f�X�g���N�^
	~GameManager();

	Player *player;
	Field *field;
	BackGround *backGround;
};


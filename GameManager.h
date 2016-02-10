
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

	// �R���X�g���N�^
	GameManager();

public:

	static GameManager* instance ;

	// �V���O���g��
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

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

public:

	// �f�X�g���N�^
	~GameManager();

	// �e�C���X�^���X�𐶐�

	Player *player;

	Field *field;

};


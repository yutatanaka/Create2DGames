
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

	// �R���X�g���N�^
	GameManager();

	// �f�X�g���N�^
	~GameManager();

	// ���������\�b�h
	void Initialize();

	//Player *player;

};

extern GameManager gameManager;
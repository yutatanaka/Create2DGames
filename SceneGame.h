
#pragma once

#include "Vec2f.h"

class SceneGame
{
public:

	// �R���X�g���N�^
	SceneGame();

	// �f�X�g���N�^
	~SceneGame();

	// ���������\�b�h
	void Initialize();

	// �X�V���\�b�h
	void Update();

	// �`�惁�\�b�h
	void Draw();

public:

	// ���W
	Vec2f position;

	// �w�i�̉摜�n���h��
	int gameBackGroundHandle;

};

#pragma once 

#include "GameManager.h"
#include "Vec2.h"

class SceneTitle
{
public:

	// �R���X�g���N�^
	SceneTitle();

	// �f�X�g���N�^
	~SceneTitle();

	// ���������\�b�h
	void Initialize();

	// �X�V���\�b�h
	void Update();

	// �`�惁�\�b�h
	void Draw();

public:

	// ���W
	Vec2 position;

	// �N���A��ʂ̔w�i�n���h��
	int titleBackGroundHandle;
};
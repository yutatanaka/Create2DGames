
#pragma once

#include "GameManager.h"
#include "Vec2.h"

class SceneClear
{
public:

	// �R���X�g���N�^
	SceneClear();

	// �f�X�g���N�^
	~SceneClear();

	// ���������\�b�h
	void Initialize();

	// �X�V���\�b�h
	void Update();

	// �`�惁�\�b�h
	void Draw();

public:

	// ���W
	Vec2 position;

	// �N���A��ʔw�i�̊i�[�p�n���h��
	int clearBackGroundHandle;
};
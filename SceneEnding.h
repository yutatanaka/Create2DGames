
#pragma once

#include "GameManager.h"

class SceneEnding
{
public:

	// �R���X�g���N�^
	SceneEnding();

	// �f�X�g���N�^
	~SceneEnding();

	// ���������\�b�h
	void Initialize();

	// �X�V���\�b�h
	void Update();

	// �`�惁�\�b�h
	void Draw();

public:

	// �Q�[���I�[�o�[���̉摜�n���h��
	int gameOverPomeHandle;

	// �`�掞�̍��W
	
	// x���W
	const int k_X = 700;
	
	// y���W
	const int k_Y = 480;

	const int kColor_White = GetColor(255, 255, 255);

};
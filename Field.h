
#pragma once

#define MAP_SIZE 64		// �}�b�v�`�b�v1�̃h�b�g�T�C�Y
#define MAP_WIDTH 16	// �}�b�v�̕�
#define MAP_HEIGHT 12	// �}�b�v�̏c����

class Field
{
public:
	
	// �R���X�g���N�^
	Field();

	// �f�X�g���N�^
	~Field();

	// �X�V
	void Update();
	
	// �`��
	void Draw();

private:

	int x, y;

	// �}�b�v�̃f�[�^
	int MapData[MAP_HEIGHT][MAP_WIDTH] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
};
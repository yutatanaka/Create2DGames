
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

public:

	// �}�b�v�̃f�[�^ 
	int MapData[MAP_HEIGHT][MAP_WIDTH];


private:

	// x���A����
	int x_axis, y_axis;
};

extern Field field;
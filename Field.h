
#pragma once

#include "Vec2.h"
#include "Player.h"

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

	// �X�V���\�b�h
	void Update();
	
	// �`�惁�\�b�h
	void Draw();

	// �����蔻�胁�\�b�h
	bool CollisionDetection(Vec2 pos);

public:

	// �}�b�v�̃f�[�^ 
	int MapData[MAP_HEIGHT][MAP_WIDTH];


private:

	// x���A����
	int x_axis, y_axis;
};


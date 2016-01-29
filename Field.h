
#pragma once

#include <vector>
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

	// ���������\�b�h
	void Initialize();

	// �X�V���\�b�h
	void Update();
	
	// �`�惁�\�b�h
	void Draw();

	// �v���C���[�Ə��Ƃ̓����蔻�胁�\�b�h
	void CheckHit(Player& player);


public:

	// �}�b�v�̃f�[�^ 
	int mapData[MAP_HEIGHT][MAP_WIDTH];

	// ���W
	int x, y;

	// ��
	int boxWidth, boxHeight;

	//�������͂���
	Vec2 distance;

private:

	// �t�B�[���h�p�̃n���h��
	int blockGraphicHandle;

};

//std::vector<std::vector<int>> boxArray;

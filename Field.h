
#pragma once

#include <vector>
#include "Vec2f.h"
#include "Player.h"

#define MAP_SIZE 64		// �}�b�v�`�b�v1�̃h�b�g�T�C�Y
#define MAP_WIDTH 25	// �}�b�v�̕�
#define MAP_HEIGHT 15	// �}�b�v�̏c����


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
	void CheckHit(Player& player, int x, int y);


public:

	// �}�b�v�̃f�[�^ 
	int mapData[MAP_HEIGHT][MAP_WIDTH];

	// ���W
	int x, y;

	// ��
	int boxWidth, boxHeight;

	//�������͂���
	Vec2f distance;

private:

	// �t�B�[���h�p�̃n���h��
	int groundGraphicHandle;

};
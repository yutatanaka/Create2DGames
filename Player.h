
#pragma once

#include "GameManager.h"
#include "Vec2f.h"
#include "Vec2i.h"
#include "Field.h"

class Player
{
private:

	// ���͏������\�b�h
	void Input();

	// �d�͏������\�b�h
	void Gravity();

	// �ړ����䃁�\�b�h
	void MovementControl();

public: 

	// �R���X�g���N�^
	Player();

	// �������������\�b�h
	void Initialize();

	// �X�V�������\�b�h
	void Update();

	// �`�揈�����\�b�h
	void Draw();

	// �������Ă���Ƃ��̏������\�b�h
	void IsHit(Field& field);

	// �v���C���[�̌��݁A���W�擾���\�b�h
	Vec2i GetMapPosition()const;

	// �v���C���[�̉��̃}�b�v�f�[�^�𒲂ׂ�
	int CheckUnder();

private:

	// �ړ��W��
	float move;

	// y�����̃X�s�[�h
	float y_speed;

	// �d��
	float gravity;

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

////////////////////////////////////

	// move�z��v�f��(�萔)
	const int kMoveNumberElements = MoveNumberElements;

	// wait�z��v�f��(�萔)
	const int kWaitNumberElements = WaitNumberElements;

	// �������x(�萔)
	const int kSpeed = 3;

	// 1�s�N�Z�����]������������(�萔)
	const int kMargin = 1;

	// ���������W(�萔)
	const float kDefault_x = 10;

	// ���������W(�萔)
	const float kDefault_y = 800;

public:

	// �L�����N�^�[�̍��W
	Vec2i position;

	// �L�����N�^�[�̑傫��
	Vec2f scale;

	// �W�����v���Ă��邩�ǂ����̃t���O
	bool isJump;

/////////////////////////////////////////

	// �摜�̕�
	int charaWidth, charaHeight;

	// move�O���t�B�b�N�n���h���i�[�p�z��
	int moveGraphicHandle[6];
	
	// wait�O���t�B�b�N�n���h���i�[�p�z��
	int waitGraphicHandle[4];

	// move�p�������̃J�E���g��
	int move_xCount;
	
	// wait�p�������̃J�E���g��
	int wait_xCount;

	// move�Y���p�ϐ�
	int moveImageX, moveResult;

	// wait�Y���p�ϐ�
	int waitImageX, waitResult;
};
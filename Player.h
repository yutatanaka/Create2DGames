
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

	// �摜�A�j���[�V�������\�b�h
	void Animation();

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

	// �E�������Ă��邩�ǂ����̃t���O
	bool isRight;

//////////////////////////////////////////////////////////

	// �������x(�萔)
	const int kSpeed = 5;

	// 1�s�N�Z�����]������������(�萔)
	const int kMargin = 1;

public:

	// �L�����N�^�[�̍��W
	Vec2i position;

	// �L�����N�^�[�̑傫��
	Vec2f scale;

	// �W�����v���Ă��邩�ǂ����̃t���O
	bool isJump;

	// �����Ă邩�ǂ����̃t���O
	bool isLive;

	// ���������W(�萔)
	const float kDefault_x = 65;

	// ���������W(�萔)
	const float kDefault_y = 770;

/////////////////////////////////////////

	// �摜�̕�
	int charaWidth, charaHeight;

	// move�O���t�B�b�N�n���h���i�[�p�z��
	int moveGraphicHandle[MoveNumberElements];
	
	// wait�O���t�B�b�N�n���h���i�[�p�z��
	int waitGraphicHandle[WaitNumberElements];

	// jump�O���b�t�B�b�N�n���h���i�[�p�ϐ�
	int jumpGraphicHandle;

	// move�p�������̃J�E���g��
	int move_xCount;
	
	// wait�p�������̃J�E���g��
	int wait_xCount;

	// move�Y���p�ϐ�
	int moveImageX, moveResult;

	// wait�Y���p�ϐ�
	int waitImageX, waitResult;
};
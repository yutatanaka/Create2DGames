
#include "DxLib.h"
#include "GameManager.h"
#include "Field.h"
#include "Player.h"

// �L�[�擾�p�z��
extern char key[256];

// �R���X�g���N�^
Player::Player() :
position(10, 684),// �����ʒu
width (29),		  // ��
height(40),		  // ���� 
xCount (),		  // �������̃J�E���g��
yCount (),		  // �c�����̃J�E���g��
imageX (),		  // �Y���p�ϐ�	
imageY (),		  // �Y���p�ϐ�
result (),
move(1.0f),		  // �ړ��W��
jumpPower(),	  // �W�����v��
gravity(),		  // �d��
isJump(false),	  // �W�����v���Ă��邩�̃t���O(�����ݒ�F���ĂȂ����)
isLive(true)	  // �����Ă��邩�̃t���O(�����ݒ�F�����Ă���)
{

	// �摜�ǂݍ���
	if (-1 == LoadDivGraph("res/player/charcter.png", 12, 3, 4, 29, 40 , graphicHandle, 0))
	{
		printf("�G���[����");
	}

}


// �X�V����
void Player::Update()
{

	Input();

}


// ���͏���
void Player::Input()
{
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
	{
		// �ړ��W����0.71�ɐݒ�
		move = 0.71f;

	}

	//�@���L�[�������ꂽ��
	if (key[KEY_INPUT_LEFT] == 1)
	{
		position.x -= kSpeed * move;
	}

	// ���L�[�������ꂽ��
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		position.x += kSpeed * move;
	}
	

	// ���L�[��������ĂāA����xCount��0�ȏ�Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_LEFT] == 1)
	{
		if (xCount > 0)
		{
			xCount = 0;
		}
		--xCount;
	}

	// ���L�[��������ĂāA����xCount��0�ȉ��Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		if (xCount < 0)
		{
			xCount = 0;
		}
		++xCount;
	}

	// �J�E���g������Y�������߂�
	imageX = abs(xCount) % 30 / 10;
	imageY = abs(yCount) % 30 / 10;

	// x�J�E���g���v���X�Ȃ�E�����Ȃ̂�2�s�ڂ̐擪�Y���ԍ��𑫂�
	if (xCount > 0)
	{
		imageX += 6;
		result = imageX;
	}
	else if (xCount < 0)
	{
		// �}�C�i�X�Ȃ獶�����Ȃ̂ŁA4�s�ڂ̐擪�Y���ԍ��𑫂�

		imageX += 3;
		result = imageX;
	}

	// �΂߈ړ��̏ꍇ�͉����D��
	if (move == 0.71f)
	{
		result = imageX;
	}

	// ������ĂȂ���΃J�E���g��0�ɂ���
	if (key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1)
	{
		xCount = 0;
	}

////////////////////////////////////////////////////////////
	
	// ��������
	position.y -= gravity;

	// ���������x��������
	position.y += 2;

	// �����n�ʂɂ��Ă�����~�܂�
	if (position.y > 684)
	{
		position.y = 684;
		jumpPower = 0;
	}

	// SPECE�������Ă��āA�n�ʂɂ�����W�����v
	if (key[KEY_INPUT_SPACE] == 1 && position.y == 684)
	{
		isJump = true;
		jumpPower -= 30;
		position.y += jumpPower;
	}
	isJump = false;
}


// �`�揈��
void Player::Draw()
{
	// �����Ă�Ε`��
	if (isLive)
	{
		// �`��
		DrawGraph(position.x - width / 2, position.y - height / 2, graphicHandle[result], TRUE);
	}
}

#include "DxLib.h"
#include "GameManager.h"
#include "Field.h"
#include "Player.h"

// �R���X�g���N�^
Player::Player() :
position(32, 640),// �����ʒu
width (29),		  // ��
height(40),		  // ���� 
xCount (),		  // �������̃J�E���g��
yCount (),		  // �c�����̃J�E���g��
imageX (),		  // �Y���p�ϐ�	
imageY (),		  // �Y���p�ϐ�
result (),
move(2.0f),		  // �ړ��W��
jumpPower(),	  // �W�����v��
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

	if (CheckHitKey(KEY_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		// �ړ��W����0.71�ɐݒ�
		move = 0.71f;

	}

	//�@���L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		position.x -= kSpeed * move;
	}

	// ���L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		position.x += kSpeed * move;
	}
	

	// ���L�[��������ĂāA����xCount��0�ȏ�Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (xCount > 0)
		{
			xCount = 0;
		}
		--xCount;
	}

	// ���L�[��������ĂāA����xCount��0�ȉ��Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
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

	// ������ĂȂ���΃J�E���g��0�ɂ���
	if (CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1)
	{
		xCount = 0;
	}

////////////////////////////////////////////////////////////
	

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

// �d�͂������鏈��
void Player::Gravity()
{
	// �W�����v�����ĂȂ���Ώd�͂������Ȃ�
	if (!isJump) { return; }

	position.y += jumpPower;
	jumpPower -= 1.0f;
}
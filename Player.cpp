
#include "DxLib.h"
#include  "Player.h"


// �R���X�g���N�^
Player::Player()
{

	// �摜�ǂݍ���
	if (-1 == LoadDivGraph("res/player/charcter.png", 12, 3, 4, 29, 40, graphicHandle))
	{
		printf("�G���[����");
	}
	width = 29;
	height = 40;

	// �ړ��W��
	move = 1.0f;

	// �������Əc�����̃J�E���g��
	xCount = 0, yCount = 0;

	// �Y���p�ϐ�
	imageX = 0, imageY = 0, result = 0;

	// �����ʒu
	x = 180;
	y = 400;

	isLive = true;
}


// �X�V����
void Player::Update()
{

	Draw();

	Input();

}


// ���͏���
void Player::Input()
{

	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
	{
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
		{
			// �ړ��W����0.71�ɐݒ�
			move = 0.71f;
		}
		else
		{
			// �΂߂���Ȃ����1.0�ɐݒ�
			move = 1.0f;
		}
	}
	else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
	{
		move = 1.0f;
	}

	//�@���L�[�������ꂽ��
	if (key[KEY_INPUT_LEFT] == 1)
	{
		x -= kSpeed * move;
	}

	// ���L�[�������ꂽ��
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		x += kSpeed * move;
	}
	
	// ���L�[�������ꂽ��
	if (key[KEY_INPUT_UP] == 1)
	{
		y -= kSpeed * move;
	}

	// ���L�[�������ꂽ��
	if (key[KEY_INPUT_DOWN] == 1)
	{
		y += kSpeed * move;
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

	// ���L�[��������ĂāA����yCount��0�ȏ�Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_UP] == 1)
	{
		if (yCount > 0)
		{
			yCount = 0;
		}
		--yCount;
	}

	// ���L�[��������ĂāA����yCount��0�ȉ��Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_DOWN] == 1)
	{
		if (yCount < 0)
		{
			yCount = 0;
		}
		++yCount;
	}


	// �J�E���g������Y�������߂�
	imageX = abs(xCount) % 30 / 10;
	imageY = abs(yCount) % 30 / 10;

	// x�J�E���g���v���X�Ȃ�E�����Ȃ̂�2�s�ڂ̐擪�Y���ԍ��𑫂�
	if (xCount > 0)
	{
		imageX += 3;
		result = imageX;
	}
	else if (xCount < 0)
	{
		// �}�C�i�X�Ȃ獶�����Ȃ̂ŁA4�s�ڂ̐擪�Y���ԍ��𑫂�

		imageX += 9;
		result = imageX;
	}

	// y�J�E���g���v���X�Ȃ牺�����Ȃ̂ŁA3�s�ڂ̐擪�Y���ԍ��𑫂�
	if (yCount > 0)
	{
		imageY += 6;
		result = imageY;
	}
	else if (yCount < 0)
	{
		// 1�s�ڂ̐擪�Y���ԍ���0�Ȃ̂ŉ������Ȃ�
		imageY += 0;
		result = imageY;
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
	if (key[KEY_INPUT_UP] != 1 && key[KEY_INPUT_DOWN] != 1)
	{
		yCount = 0;
	}
}


// �`�揈��
void Player::Draw()
{
	// �����Ă�Ε`��
	if (isLive)
	{
		// �`��
		DrawGraph(x - width / 2, y - height / 2, graphicHandle[result], TRUE);
	}
}

#include "DxLib.h"
#include "GameManager.h"
#include "Key.h"
#include "Field.h"
#include "Player.h"

// �R���X�g���N�^
Player::Player() :
position(10, 800),		 // �����ʒu
charaWidth (100),		 // ��
charaHeight(100),		 // ���� 
moveGraphicHandle(),	 // move�O���t�B�b�N�n���h���i�[�p�z��
waitGraphicHandle(),	 // wait�O���t�B�b�N�n���h���i�[�p�z��
move_xCount (0),		 // move�p,�������̃J�E���g��
wait_xCount (0),		 // wait�p,�������̃J�E���g��
moveImageX (0),			 // move�Y���p�ϐ�	
waitImageX (0),			 // wait�Y���p�ϐ�
moveResult (0),			 
waitResult (0),
move(1.0f),	      // �ړ��W��
y_speed(0),		  // y�����̃X�s�[�h
gravity(0.5f),	  // �d��
isJump(false),	  // �W�����v���Ă��邩�̃t���O(�����ݒ�F���ĂȂ����)
isLive(true)	  // �����Ă��邩�̃t���O(�����ݒ�F�����Ă���)
{
	moveGraphicHandle[MoveNumberElements] = { 0 };
	waitGraphicHandle[WaitNumberElements] = { 0 };
}

// ����������
void Player::Initialize()
{
	//�摜�ǂݍ���
	LoadDivGraph("res/player/charcter.png", 12, 3, 4, charaWidth, charaHeight, moveGraphicHandle, TRUE);
}

// �X�V����
void Player::Update()
{

	Input();

	Gravity();

	MovementControl();

}

// �`�揈��
void Player::Draw()
{
	// �����Ă�Ε`��
	if (isLive)
	{
		// �`��
		DrawGraph(position.x, position.y, graphicHandle[result], TRUE);
	}
}

// �������Ă��鎞�̏������\�b�h
void Player::IsHit(Field& field)
{
	field.distance.x = position.x + charaWidth / 2 - (field.x * MAP_SIZE + field.boxWidth / 2);
	field.distance.y = position.y + charaHeight / 2 - (field.y * MAP_SIZE + field.boxHeight / 2);

	if (field.distance.x >= 0) field.distance.x *= -1;
	if (field.distance.y >= 0) field.distance.y *= -1;

	if (field.distance.x < field.distance.y)
	{
		if (position.x < field.x * MAP_SIZE)
		{
			position.x += field.x * MAP_SIZE - (position.x + charaWidth);
			y_speed = 0;
		}
		else
		{
			position.x += field.x * MAP_SIZE + field.boxWidth - position.x;
			y_speed = 0;
		}
	}
	else if (field.distance.x > field.distance.y)
	{
		if (position.y < field.y * MAP_SIZE)
		{
			position.y += field.y * MAP_SIZE - (position.y + charaHeight);
			y_speed = 0;
		}
		else
		{
			position.y += field.y * MAP_SIZE + field.boxHeight - position.y;
			y_speed = 0;
		}
	}
	
}

// ���͏���
void Player::Input()
{

	if (CheckHitKey(KEY_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		// �ړ��W����0.71�ɐݒ�
		move = 0.71;

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

	// ���L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		position.y -= kSpeed * move;

	}

	// ���L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		position.y += kSpeed * move;

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

	// Space�L�[��������Ă���
	if (key.keys[KEY_INPUT_SPACE] == 1 && CheckUnder() != 0)
	{
		// �W�����v����
		isJump = true;
		y_speed = -10;

		// �v���C���[�̉��𒲂ׂ�
		if (CheckUnder() == 0)
		{
			// �W�����v���Ȃ�
			isJump = false;
		}
	}
}

// �d�͂������鏈��
void Player::Gravity()
{

	y_speed += gravity;
	position.y += y_speed;

}

// �ړ����䃁�\�b�h
void Player::MovementControl()
{
	// �L�����̈ړ�����
	if (position.x > Width)
	{
		position.x = Width - kMargin;
	}
	else if (position.x < kMargin)
	{
		position.x = kMargin;
	}

	if (position.y > Height)
	{
		//position.y = Height - kMargin;
		isLive = false;

		if (isLive == false)
		{
			position.x = kDefault_x;
			position.y = kDefault_y;
			isLive = true;
		}
	}
	else if (position.y < kMargin)
	{
		position.y = kMargin;
	}
}

// �v���C���[�̌��݂̍��W�擾���\�b�h
Vec2i Player::GetMapPosition()const
{
	Vec2i v;

	int mapX, mapY = 0;
	mapX = position.x / (Width / MAP_WIDTH);
	mapY = position.y / (Height / MAP_HEIGHT);

	v.x = mapX;
	v.y = mapY;
	return v;

	//return GameManager::GetInstance()->field->mapData[mapX][mapY];
}

// �v���C���[�̉��𒲂ׂ�(�}�b�v�f�[�^)
int Player::CheckUnder()
{

	Vec2i v = GetMapPosition();

	if (MAP_HEIGHT <= (v.y + 1)){
		return 0;
	}
	else
	{
		return GameManager::GetInstance()->field->mapData[v.y + 1][v.x];
	}

}

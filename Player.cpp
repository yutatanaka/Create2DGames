
#include "DxLib.h"
#include "GameManager.h"
#include "Key.h"
#include "Sound.h"
#include "Field.h"
#include "Enemy.h "
#include "Player.h"

// �R���X�g���N�^
Player::Player() :
position(64, 770),		 // �����ʒu
charaWidth (60),		 // ��
charaHeight(60),		 // ���� 
moveGraphicHandle(),	 // move�O���t�B�b�N�n���h���i�[�p�z��
waitGraphicHandle(),	 // wait�O���t�B�b�N�n���h���i�[�p�z��
move_xCount (0),		 // move�p,�������̃J�E���g��
wait_xCount (0),		 // wait�p,�������̃J�E���g��
moveImageX (0),			 // move�Y���p�ϐ�	
waitImageX (0),			 // wait�Y���p�ϐ�
moveResult (0),			 
waitResult (0),
move(1.0f),				 // �ړ��W��
y_speed(0),				 // y�����̃X�s�[�h
gravity(0.5f),			 // �d��
isJump(false),			 // �W�����v���Ă��邩�ǂ����̃t���O(�����ݒ�F���ĂȂ����)
isLive(true),			 // �����Ă��邩�ǂ����̃t���O(�����ݒ�F�����Ă���)
isGoal(false),			 // �S�[���n�_�ɂ��邩�ǂ����̃t���O(�����ݒ�F�S�[�����ĂȂ����)
isRight(true)			 // �E�������Ă��邩�ǂ����̃t���O(�����ݒ�F�E�������Ă���)
{
	moveGraphicHandle[MoveNumberElements] = { 0 };
	waitGraphicHandle[WaitNumberElements] = { 0 };
}

// ����������
void Player::Initialize()
{
	// Move�摜�ǂݍ���
	LoadDivGraph("res/player/playerMove.png", MoveNumberElements, 3, 2, charaWidth, charaHeight, moveGraphicHandle, TRUE);

	// Wait�摜�ǂݍ���
	LoadDivGraph("res/player/playerWait.png", WaitNumberElements, 2, 2, charaWidth, charaHeight, waitGraphicHandle, TRUE);

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
	// �����Ă��āA���L�[�������́��L�[��������Ă����
	if (isLive == true ) 
	{
		if (CheckHitKey(KEY_INPUT_LEFT) != 0 || CheckHitKey(KEY_INPUT_RIGHT) != 0)
		{
			// �`�悷��
			DrawGraph(position.x, position.y, moveGraphicHandle[moveResult], TRUE);
		}
	}

	// �����Ă��āA���L�[�����L�[��������Ă��Ȃ����
	if (isLive == true)	
	{
		if (CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1)
		{
			// �`�悷��
			DrawGraph(position.x, position.y, waitGraphicHandle[waitResult], TRUE);
		}
	}
}

// �Œ�̏��Ƃ̓������Ă��鎞�̏������\�b�h
void Player::FieldIsHit(Field& field)
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
		}
		else
		{
			position.x += field.x * MAP_SIZE + field.boxWidth - position.x;
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
	
	Animation();


	char hoge[256];
	sprintf_s(hoge,255,"%d\n",CheckLeft());
	OutputDebugString(hoge);

	// Space�L�[�������ꂽ��
	if (key.keys[KEY_INPUT_SPACE] == 1 && CheckUnder() == 1)
	{
		PlaySoundFile("res/sound/jump.mp3", DX_PLAYTYPE_BACK);
		// �W�����v����
 		isJump = true;
		y_speed = -10;

		// �v���C���[�̉��̃}�b�v�f�[�^�𒲂ׂ�
		if (CheckUnder() != 1)
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

	}
	else if (position.y < kMargin)
	{
		position.y = kMargin;
	}
}

// �A�j���[�V�������\�b�h
void Player::Animation()
{
	// ���L�[��������ĂāA����xCount��0�ȏ�Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (move_xCount > 0)
		{
			move_xCount = 0;
		}
		--move_xCount;

		isRight = false;
	}

	// ���L�[��������ĂāA����xCount��0�ȉ��Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (move_xCount < 0)
		{
			move_xCount = 0;
		}
		++move_xCount;

		isRight = true;
	}

	// �J�E���g������Y�������߂�
	moveImageX = abs(move_xCount) % 30 / 10;
	waitImageX = abs(wait_xCount) % 20 / 10;

	// x�J�E���g���v���X�Ȃ�E�����Ȃ̂�2�s�ڂ̐擪�Y���ԍ��𑫂�
	if (move_xCount > 0)
	{
		moveImageX += 0;
		moveResult = moveImageX;
	}
	else if (move_xCount < 0)
	{
		// �}�C�i�X�Ȃ獶�����Ȃ̂ŁA4�s�ڂ̐擪�Y���ԍ��𑫂�

		moveImageX += 3;
		moveResult = moveImageX;
	}

	// ������ĂȂ���΃J�E���g��0�ɂ���
	if (CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1)
	{
		move_xCount = 0;

		// �E�������Ă����
		if (isRight == true)
		{
			if (wait_xCount < 0)
			{
				wait_xCount = 0;
			}
			++wait_xCount;
		}

		// ���������Ă����
		if (isRight == false)
		{
			if (wait_xCount > 0)
			{
				wait_xCount = 0;
			}
			--wait_xCount;
		}
	}
	else
	{
		wait_xCount = 0;
	}

	// x�J�E���g���v���X�Ȃ�E�����Ȃ̂�1�s�ڂ̐擪�Y���ԍ��𑫂�
	if (wait_xCount > 0)
	{
		waitImageX += 0;
		waitResult = waitImageX;
	}
	else if (wait_xCount < 0)
	{
		// �}�C�i�X�Ȃ獶�����Ȃ̂ŁA2�s�߂̐擪�Y���ԍ�������
		waitImageX += 2;
		waitResult = waitImageX;
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

	if (MAP_HEIGHT <= (v.y + 1))
	{
		return 0;
	}
	else
	{
		if (GameManager::GetInstance()->field->mapData[v.y + 1][v.x] == 1)
		{
			return 1;
		}
		else if (GameManager::GetInstance()->field->mapData[v.y + 1][v.x + 1] == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

// �v���C���[�̍��𒲂ׂ�(�}�b�v�f�[�^)
int Player::CheckLeft()
{
	Vec2i v = GetMapPosition();

	if (MAP_WIDTH <= (v.x - 1))
	{
		return 0;
	}
	else
	{
		return GameManager::GetInstance()->field->mapData[v.y][v.x - 1];
	}
}

// �v���C���[�̉E�𒲂ׂ�(�}�b�v�f�[�^)
int Player::CheckRight()
{
	Vec2i v = GetMapPosition();

	if (MAP_WIDTH <= (v.x + 1))
	{
		return 0;
	}
	else
	{
		return GameManager::GetInstance()->field->mapData[v.y][v.x + 1];
	}
}
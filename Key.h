
#pragma once

class Key
{
public:

	// �R���X�g���N�^
	Key();

	// �f�X�g���N�^
	~Key();

	// �L�[�̓��͏�Ԃ��X�V����
	int UpdateKey();

public:

	// �L�[��������Ă���t���[�������i�[����
	int keys[256];

	// ���݂̃L�[�̓��͏�Ԃ��i�[����
	char tmpKey[256];
};

extern Key key;
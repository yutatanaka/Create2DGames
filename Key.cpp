
#include "DxLib.h"
#include "Key.h"

Key key;

// �R���X�g���N�^
Key::Key()
{
	keys[256] = { 0 };
	tmpKey[256] = { 0 };
}

// �f�X�g���N�^
Key::~Key()
{
}

// �L�[�̓��͏�Ԃ��X�V����
int Key::UpdateKey()
{
	// �S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(tmpKey); 

	for (int i = 0; i < 256; ++i)
	{
		if (tmpKey[i] != 0)	// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		{
			keys[i]++;		// ���Z
		}
		else				// ������Ă��Ȃ����
		{
			keys[i] = 0;		// 0�ɂ���
		}
	}
	return 0;
}

#pragma once

class Sound
{
public:

	// �R���X�g���N�^
	Sound();

	// �f�X�g���N�^
	~Sound();

	// �������������\�b�h
	void Initialize();

public:

	// �Q�[����ʂ�
	int gameBackGroundHandle;

	// ����{�^���Ȃǂ��������Ƃ���SE
	int dicitionSoundHandle;

	// �^�C�g����ʂŗ����BGM
	int titleBackGroundHandle;

	// �N���A��ʂŗ����BGM
	int clearBackGroundHandle;

	// �v���C���[���W�����v���[�V�����̎���SE
	int jumpSoundHandle;
};

extern Sound sound;

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

	// ����{�^���Ȃǂ��������Ƃ���SE
	int dicitionSoundHandle;

	// �Q�[����ʂŗ����BGM
	int gameMusicHandle;

	// �Q�[���I�[�o�[�ŗ����BGM
	int gameOverMusicHandle;

	// �N���A��ʂŗ����BGM
	int clearMusicHandle;

	// �v���C���[���ҋ@���[�V�����̎���SE
	int dogSoundHandle;

	// �v���C���[���W�����v���[�V�����̎���SE
	int jumpSoundHandle;
};

extern Sound sound;

#pragma once

class BackGround
{
public:
	// �R���X�g���N�^
	BackGround();

	// ���������\�b�h
	void Initialize();

	// �X�V���\�b�h
	void Update();

	// �`�惁�\�b�h
	void Draw();

private:

	// �����A��
	int x, y;

	// �i�[�p�n���h��
	int backGraphicHandle;

	// 10�s�N�Z�����̗]��(�萔)
	const int kMargin = 10;
};
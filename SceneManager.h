
#pragma once

#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneEnding.h"

// �V�[���̓��e
typedef enum
{
	eScene_Title,		// �^�C�g�����
	eScene_Game,		// �Q�[�����
	eScene_Clear,		// �N���A���
	eScene_Ending,		// �G���f�B���O���

}eScene ;

class SceneTitle;
class SceneGame;
class SceneClear;
class SceneEnding;

class SceneManager
{
private:

	// �R���X�g���N�^
	SceneManager();


public:

	// �f�X�g���N�^
	~SceneManager();

	// �V���O���g��
	static SceneManager* GetInstance()
	{
		if (nullptr == instance)
		{
			instance = new SceneManager();
		}
		return instance;
	}

	static SceneManager* DeleteInstance()
	{
		delete instance;

		return instance;
	}

	// ���������\�b�h
	void Initialize();

	// �X�V���\�b�h
	void Update();

	// �`�惁�\�b�h
	void Draw();

	// ���� nextScene �ɃV�[����ύX����
	void SceneManager_ChangeScene(eScene nextScene);

public:

	// �e�N���X�̃C���X�^���X�𐶐�
	static SceneManager* instance;

	SceneTitle *sceneTitle;

	SceneGame *sceneGame;

	SceneClear *sceneClear;

	SceneEnding *sceneEnding;

};
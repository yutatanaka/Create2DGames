
#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;
static eScene scene = eScene_Title;	// �V�[���Ǘ��ϐ�


// �R���X�g���N�^
SceneManager::SceneManager()
{
	sceneTitle = new SceneTitle();

	sceneGame = new SceneGame();

	sceneClear = new SceneClear();

	sceneGameOver = new SceneGameOver();
}

// �f�X�g���N�^
SceneManager::~SceneManager()
{
	delete sceneTitle;

	delete sceneGame;

	delete sceneClear;

	delete sceneGameOver;
}

// ���������\�b�h
void SceneManager::Initialize()
{
}

// �X�V���\�b�h
void SceneManager::Update()
{
	switch (scene)				// �V�[���ɂ���ď����𕪊�
	{
	case eScene_Title:			// ���݂̉�ʂ��^�C�g���Ȃ�
		sceneTitle->Update();	// �^�C�g����ʂ̍X�V����������
		break;
	case eScene_Game:			// ���݂̉�ʂ��Q�[���Ȃ�
		sceneGame->Update();	// �Q�[����ʂ̍X�V����������
		break;
	case eScene_Clear:			// ���݂̉�ʂ��N���A�Ȃ�
		sceneClear->Update();	// �N���A��ʂ̍X�V����������
		break;
	case eScene_GameOver:		// ���݂̉�ʂ��Q�[���I�[�o�[�Ȃ�
		sceneGameOver->Update();// �Q�[���I�[�o�[��ʂ̍X�V����������
		break;

	}
}

// �`�惁�\�b�h
void SceneManager::Draw()
{
	switch (scene)				// �V�[���ɂ���ď����𕪊�
	{
	case eScene_Title:			// ���݂̉�ʂ��^�C�g���Ȃ�
		sceneTitle->Draw();		// �^�C�g����ʂ̕`�揈��������
		break;
	case eScene_Game:			// ���݂̉�ʂ��Q�[���Ȃ�
		sceneGame->Draw();		// �Q�[����ʂ̕`�揈��������
		break;
	case eScene_Clear:			// ���݂̉�ʂ��N���A�Ȃ�
		sceneClear->Draw();		// �N���A��ʂ̕`�揈��������
		break;
	case eScene_GameOver:		// ���݂̉�ʂ��Q�[���I�[�o�[�Ȃ�
		sceneGameOver->Draw();	// �Q�[���I�[�o�[��ʂ̕`�揈��������
		break;
	}


}

// ���� nextScene �V�[����ύX����
void SceneManager::SceneManager_ChangeScene(eScene nextScene)
{
	scene = nextScene;
}
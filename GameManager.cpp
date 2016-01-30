
#include "GameManager.h"
#include "BackGround.h"
#include "Field.h"
#include "Player.h"

GameManager gameManager;

// �R���X�g���N�^
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
	backGround = new BackGround();
}

// �f�X�g���N�^
GameManager::~GameManager()
{
	delete player;
	delete field;
}

// ����������
void GameManager::Initialize()
{
	backGround->Initialize();

	field->Initialize();

	player->Initialize();

}

void GameManager::Update()
{
	backGround->Update();

	field->Update();
	
	player->Update();

}

void GameManager::Draw()
{
	backGround->Draw();

	field->Draw();
	
	player->Draw();

}
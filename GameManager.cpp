
#include "GameManager.h"
#include "Field.h"
#include "Player.h"


// �R���X�g���N�^
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
}

// �f�X�g���N�^
GameManager::~GameManager()
{
	delete player;
	delete field;
}

void GameManager::Update()
{

	field->PlayerNowPosition(player->GetPosition());

	field->Update();
	
	player->Update();

}

void GameManager::Draw()
{

	field->Draw();
	
	player->Draw();

}
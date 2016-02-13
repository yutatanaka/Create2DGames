
#include "GameManager.h"
#include "Field.h"
#include "MoveFloor.h"
#include "Player.h"

GameManager* GameManager::instance = nullptr;

// �R���X�g���N�^
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
	moveFloor = new MoveFloor();
}

// �f�X�g���N�^
GameManager::~GameManager()
{
	delete player;
	delete field;
	delete moveFloor;
}

// ����������
void GameManager::Initialize()
{

	field->Initialize();

	moveFloor->Initialize();

	player->Initialize();

}

void GameManager::Update()
{

	field->Update();

	moveFloor->Update();
	
	player->Update();

	Draw();

}

void GameManager::Draw()
{

	field->Draw();
	
	moveFloor->Draw();

	player->Draw();

}
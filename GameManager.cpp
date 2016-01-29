
#include "GameManager.h"
#include "BackGround.h"
#include "Field.h"
#include "Player.h"

GameManager gameManager;

// コンストラクタ
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
	backGround = new BackGround();
}

// デストラクタ
GameManager::~GameManager()
{
	delete player;
	delete field;
}

void GameManager::Update()
{

	field->Update();
	
	player->Update();

}

void GameManager::Draw()
{

	field->Draw();
	
	player->Draw();

}
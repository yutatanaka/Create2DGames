
#include "GameManager.h"
#include "Field.h"
#include "MoveFloor.h"
#include "Player.h"

GameManager* GameManager::instance = nullptr;

// コンストラクタ
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
	moveFloor = new MoveFloor();
}

// デストラクタ
GameManager::~GameManager()
{
	delete player;
	delete field;
	delete moveFloor;
}

// 初期化処理
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

#include "GameManager.h"
#include "Field.h"
#include "Enemy.h"
#include "Player.h"

GameManager* GameManager::instance = nullptr;

// コンストラクタ
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
	enemy = new Enemy();
}

// デストラクタ
GameManager::~GameManager()
{
	delete player;
	delete field;
	delete enemy;
}

// 初期化処理
void GameManager::Initialize()
{

	field->Initialize();

	enemy->Initialize();

	player->Initialize();

}

void GameManager::Update()
{

	field->Update();

	enemy->Update();
	
	player->Update();

	Draw();

}

void GameManager::Draw()
{

	field->Draw();
	
	enemy->Draw();

	player->Draw();

}
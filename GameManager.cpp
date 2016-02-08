
#include "GameManager.h"
#include "Field.h"
#include "Player.h"

GameManager* GameManager::instance = nullptr;

// コンストラクタ
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
}

// デストラクタ
GameManager::~GameManager()
{
	delete player;
	delete field;
}

// 初期化処理
void GameManager::Initialize()
{

	field->Initialize();

	player->Initialize();

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
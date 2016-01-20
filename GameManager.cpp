
#include "GameManager.h"
#include "Field.h"
#include "Player.h"


// コンストラクタ
GameManager::GameManager()
{
	player = new Player();
	field = new Field();
}

// デストラクタ
GameManager::~GameManager()
{
}

// 初期化
void GameManager::Initialize()
{
}

void GameManager::Update()
{

	field->CollisionDetection(player->GetPosition());

	field->Update();
	player->Update();

}

void GameManager::Draw()
{

	field->Draw();
	player->Draw();
}
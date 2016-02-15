
#include "Enemy.h"
#include "Player.h"

// コンストラクタ
Enemy::Enemy() :
bee_x(1280),
bee_y(64),
move(0, 4),
distance(0, 0),
width(64),
height(64),
beeGraphicHandle(0),
butterflyNetGraphicHandle(0)
{
}

// デストラクタ
Enemy::~Enemy()
{
}

// 初期化処理メソッド
void Enemy::Initialize()
{
	beeGraphicHandle = LoadGraph("res/enemy");
}

// 更新処理メソッド
void Enemy::Update()
{

	BeeCheckHit();

	Move();

}

// 描画処理メソッド
void Enemy::Draw()
{
	//DrawBox(x, y, x + width, y + height, GetColor(0, 255, 255), TRUE);
	DrawGraph(bee_x, bee_y, beeGraphicHandle, TRUE);
}

// 移動処理メソッド
void Enemy::Move()
{
	bee_y += move.y;
	if (bee_y < 64 || bee_y > 320)
	{
		move.y = -move.y;
	}
}


// プレイヤーと動く床との当たり判定を確認するメソッド
void Enemy::BeeCheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > bee_x && // 右端と左端
		GameManager::GetInstance()->player->position.x < bee_x + width &&			  // 左端と右端
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > bee_y &&// 下端と上端
		GameManager::GetInstance()->player->position.y < bee_y + height)			  // 上端と下端
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (bee_x + width / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (bee_y + height / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <bee_x)
			{
				GameManager::GetInstance()->player->position.x += bee_x - (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth);
			}
			else
			{
				GameManager::GetInstance()->player->position.x += bee_x + width - GameManager::GetInstance()->player->position.x;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < bee_y)
			{
				GameManager::GetInstance()->player->position.y += bee_y - (GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight);
				GameManager::GetInstance()->player->y_speed = 0;
			}
			else
			{
				GameManager::GetInstance()->player->position.y += bee_y + height - GameManager::GetInstance()->player->position.y;
				GameManager::GetInstance()->player->y_speed = 0;
			}
		}
	}
}
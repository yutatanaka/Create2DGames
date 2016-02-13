
#include "MoveFloor.h"
#include "Player.h"

// コンストラクタ
MoveFloor::MoveFloor() :
x(1280),
y(64),
move(0, 4),
distance(0, 0),
width(64),
height(64),
moveFloorGraphicHandle(0)
{
}

// デストラクタ
MoveFloor::~MoveFloor()
{
}

// 初期化処理メソッド
void MoveFloor::Initialize()
{
	moveFloorGraphicHandle = LoadGraph("res/floor/moveFloor.png");
}

// 更新処理メソッド
void MoveFloor::Update()
{

	MoveFloorCheckHit();

	Move();

}

// 描画処理メソッド
void MoveFloor::Draw()
{
	//DrawBox(x, y, x + width, y + height, GetColor(0, 255, 255), TRUE);
	DrawGraph(x, y , moveFloorGraphicHandle, TRUE);
}

// 移動処理メソッド
void MoveFloor::Move()
{
	y += move.y;
	if (y < 64 || y > 320)
	{
		move.y = -move.y;
	}
}


// プレイヤーと動く床との当たり判定を確認するメソッド
void MoveFloor::MoveFloorCheckHit()
{
	if (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth > x && // 右端と左端
		GameManager::GetInstance()->player->position.x < x + width &&			  // 左端と右端
		GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight > y &&// 下端と上端
		GameManager::GetInstance()->player->position.y < y + height)			  // 上端と下端
	{
		distance.x = GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth / 2 - (x + width / 2);
		distance.y = GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight / 2 - (y + height / 2);

		if (distance.x >= 0) distance.x *= -1;
		if (distance.y >= 0) distance.y *= -1;

		if (distance.x < distance.y)
		{
			if (GameManager::GetInstance()->player->position.x <x)
			{
				GameManager::GetInstance()->player->position.x += x - (GameManager::GetInstance()->player->position.x + GameManager::GetInstance()->player->charaWidth);
			}
			else
			{
				GameManager::GetInstance()->player->position.x += x + width - GameManager::GetInstance()->player->position.x;
			}
		}
		else if (distance.x > distance.y)
		{
			if (GameManager::GetInstance()->player->position.y < y)
			{
				GameManager::GetInstance()->player->position.y += y - (GameManager::GetInstance()->player->position.y + GameManager::GetInstance()->player->charaHeight);
				GameManager::GetInstance()->player->y_speed = 0;
			}
			else
			{
				GameManager::GetInstance()->player->position.y += y + height - GameManager::GetInstance()->player->position.y;
				GameManager::GetInstance()->player->y_speed = 0;
			}
		}
	}
}
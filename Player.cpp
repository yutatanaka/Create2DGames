
#include "DxLib.h"
#include "GameManager.h"
#include "Key.h"
#include "Field.h"
#include "Player.h"

// コンストラクタ
Player::Player() :
position(10, 800),		 // 初期位置
charaWidth (100),		 // 幅
charaHeight(100),		 // 高さ 
moveGraphicHandle(),	 // moveグラフィックハンドル格納用配列
waitGraphicHandle(),	 // waitグラフィックハンドル格納用配列
move_xCount (0),		 // move用,横方向のカウント数
wait_xCount (0),		 // wait用,横方向のカウント数
moveImageX (0),			 // move添字用変数	
waitImageX (0),			 // wait添字用変数
moveResult (0),			 
waitResult (0),
move(1.0f),	      // 移動係数
y_speed(0),		  // y方向のスピード
gravity(0.5f),	  // 重力
isJump(false),	  // ジャンプしているかのフラグ(初期設定：してない状態)
isLive(true)	  // 生きているかのフラグ(初期設定：生きてる状態)
{
	moveGraphicHandle[MoveNumberElements] = { 0 };
	waitGraphicHandle[WaitNumberElements] = { 0 };
}

// 初期化処理
void Player::Initialize()
{
	// Move画像読み込み
	LoadDivGraph("res/player/playerMove.png", MoveNumberElements, 3, 2, charaWidth, charaHeight, moveGraphicHandle, TRUE);

	// Wait画像読み込み
	LoadDivGraph("res/player/playerWait.png", WaitNumberElements, 2, 2, charaWidth, charaHeight, waitGraphicHandle, TRUE);
}

// 更新処理
void Player::Update()
{

	Input();

	Gravity();

	MovementControl();

}

// 描画処理
void Player::Draw()
{
	// 生きていて、←キーもしくは→キーが押されていれば
	if (isLive == true && CheckHitKey(KEY_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		// 描画する
		DrawGraph(position.x - charaWidth / 2, position.y - charaHeight / 2, moveGraphicHandle[moveResult], TRUE);
	}

	// 生きていて、←キーかつ→キーが押されていなければ
	if (isLive == true && CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1)
	{
		// 描画する
	}
}

// 当たっている時の処理メソッド
void Player::IsHit(Field& field)
{
	field.distance.x = position.x + charaWidth / 2 - (field.x * MAP_SIZE + field.boxWidth / 2);
	field.distance.y = position.y + charaHeight / 2 - (field.y * MAP_SIZE + field.boxHeight / 2);

	if (field.distance.x >= 0) field.distance.x *= -1;
	if (field.distance.y >= 0) field.distance.y *= -1;

	if (field.distance.x < field.distance.y)
	{
		if (position.x < field.x * MAP_SIZE)
		{
			position.x += field.x * MAP_SIZE - (position.x + charaWidth);
			y_speed = 0;
		}
		else
		{
			position.x += field.x * MAP_SIZE + field.boxWidth - position.x;
			y_speed = 0;
		}
	}
	else if (field.distance.x > field.distance.y)
	{
		if (position.y < field.y * MAP_SIZE)
		{
			position.y += field.y * MAP_SIZE - (position.y + charaHeight);
			y_speed = 0;
		}
		else
		{
			position.y += field.y * MAP_SIZE + field.boxHeight - position.y;
			y_speed = 0;
		}
	}
	
}

// 入力処理
void Player::Input()
{

	if (CheckHitKey(KEY_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		// 移動係数を0.71に設定
		move = 0.71;

	}

	//　←キーが押されたら
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		position.x -= kSpeed * move;
	}

	// →キーが押されたら
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		position.x += kSpeed * move;

	}

	// ↑キーが押されたら
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		position.y -= kSpeed * move;

	}

	// ↓キーが押されたら
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		position.y += kSpeed * move;

	}
	

	// ←キーが押されてて、かつxCountが0以上なら0にしてから1引く
	// それ以外は1引く
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (move_xCount > 0)
		{
			move_xCount = 0;
		}
		--move_xCount;
	}

	// →キーが押されてて、かつxCountが0以下なら0にしてから1足す
	// それ以外は1足す
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (move_xCount < 0)
		{
			move_xCount = 0;
		}
		++move_xCount;
	}

	// カウント数から添字を求める
	moveImageX = abs(move_xCount) % 30 / 10;
	waitImageX = abs(wait_xCount) % 20 / 10;

	// xカウントがプラスなら右向きなので2行目の先頭添字番号を足す
	if (move_xCount > 0)
	{
		moveImageX += 0;
		moveResult = moveImageX;
	}
	else if (move_xCount < 0)
	{
		// マイナスなら左向きなので、4行目の先頭添字番号を足す

		moveImageX += 3;
		moveResult = moveImageX;
	}

	// 押されてなければカウントを0にする
	if (CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1)
	{
		move_xCount = 0;
	}

	// Spaceキーが押されてたら
	if (key.keys[KEY_INPUT_SPACE] == 1 && CheckUnder() != 0)
	{
		// ジャンプする
		isJump = true;
		y_speed = -10;

		// プレイヤーの下を調べる
		if (CheckUnder() == 0)
		{
			// ジャンプしない
			isJump = false;
		}
	}
}

// 重力をかける処理
void Player::Gravity()
{

	y_speed += gravity;
	position.y += y_speed;

}

// 移動制御メソッド
void Player::MovementControl()
{
	// キャラの移動制御
	if (position.x > Width)
	{
		position.x = Width - kMargin;
	}
	else if (position.x < kMargin)
	{
		position.x = kMargin;
	}

	if (position.y > Height)
	{
		//position.y = Height - kMargin;
		isLive = false;

		if (isLive == false)
		{
			position.x = kDefault_x;
			position.y = kDefault_y;
			isLive = true;
		}
	}
	else if (position.y < kMargin)
	{
		position.y = kMargin;
	}
}

// プレイヤーの現在の座標取得メソッド
Vec2i Player::GetMapPosition()const
{
	Vec2i v;

	int mapX, mapY = 0;
	mapX = position.x / (Width / MAP_WIDTH);
	mapY = position.y / (Height / MAP_HEIGHT);

	v.x = mapX;
	v.y = mapY;
	return v;

	//return GameManager::GetInstance()->field->mapData[mapX][mapY];
}

// プレイヤーの下を調べる(マップデータ)
int Player::CheckUnder()
{

	Vec2i v = GetMapPosition();

	if (MAP_HEIGHT <= (v.y + 1)){
		return 0;
	}
	else
	{
		return GameManager::GetInstance()->field->mapData[v.y + 1][v.x];
	}

}

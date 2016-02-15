
#include "DxLib.h"
#include "GameManager.h"
#include "Key.h"
#include "Sound.h"
#include "Field.h"
#include "Enemy.h "
#include "Player.h"

// コンストラクタ
Player::Player() :
position(64, 770),		 // 初期位置
charaWidth (60),		 // 幅
charaHeight(60),		 // 高さ 
moveGraphicHandle(),	 // moveグラフィックハンドル格納用配列
waitGraphicHandle(),	 // waitグラフィックハンドル格納用配列
move_xCount (0),		 // move用,横方向のカウント数
wait_xCount (0),		 // wait用,横方向のカウント数
moveImageX (0),			 // move添字用変数	
waitImageX (0),			 // wait添字用変数
moveResult (0),			 
waitResult (0),
move(1.0f),				 // 移動係数
y_speed(0),				 // y方向のスピード
gravity(0.5f),			 // 重力
isJump(false),			 // ジャンプしているかどうかのフラグ(初期設定：してない状態)
isLive(true),			 // 生きているかどうかのフラグ(初期設定：生きてる状態)
isGoal(false),			 // ゴール地点にいるかどうかのフラグ(初期設定：ゴールしてない状態)
isRight(true)			 // 右を向いているかどうかのフラグ(初期設定：右を向いてる状態)
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
	if (isLive == true ) 
	{
		if (CheckHitKey(KEY_INPUT_LEFT) != 0 || CheckHitKey(KEY_INPUT_RIGHT) != 0)
		{
			// 描画する
			DrawGraph(position.x, position.y, moveGraphicHandle[moveResult], TRUE);
		}
	}

	// 生きていて、←キーかつ→キーが押されていなければ
	if (isLive == true)	
	{
		if (CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1)
		{
			// 描画する
			DrawGraph(position.x, position.y, waitGraphicHandle[waitResult], TRUE);
		}
	}
}

// 固定の床との当たっている時の処理メソッド
void Player::FieldIsHit(Field& field)
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
		}
		else
		{
			position.x += field.x * MAP_SIZE + field.boxWidth - position.x;
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
	
	Animation();


	char hoge[256];
	sprintf_s(hoge,255,"%d\n",CheckLeft());
	OutputDebugString(hoge);

	// Spaceキーが押されたら
	if (key.keys[KEY_INPUT_SPACE] == 1 && CheckUnder() == 1)
	{
		PlaySoundFile("res/sound/jump.mp3", DX_PLAYTYPE_BACK);
		// ジャンプする
 		isJump = true;
		y_speed = -10;

		// プレイヤーの下のマップデータを調べる
		if (CheckUnder() != 1)
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

	}
	else if (position.y < kMargin)
	{
		position.y = kMargin;
	}
}

// アニメーションメソッド
void Player::Animation()
{
	// →キーが押されてて、かつxCountが0以上なら0にしてから1引く
	// それ以外は1引く
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (move_xCount > 0)
		{
			move_xCount = 0;
		}
		--move_xCount;

		isRight = false;
	}

	// ←キーが押されてて、かつxCountが0以下なら0にしてから1足す
	// それ以外は1足す
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (move_xCount < 0)
		{
			move_xCount = 0;
		}
		++move_xCount;

		isRight = true;
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

		// 右を向いていれば
		if (isRight == true)
		{
			if (wait_xCount < 0)
			{
				wait_xCount = 0;
			}
			++wait_xCount;
		}

		// 左を向いていれば
		if (isRight == false)
		{
			if (wait_xCount > 0)
			{
				wait_xCount = 0;
			}
			--wait_xCount;
		}
	}
	else
	{
		wait_xCount = 0;
	}

	// xカウントがプラスなら右向きなので1行目の先頭添字番号を足す
	if (wait_xCount > 0)
	{
		waitImageX += 0;
		waitResult = waitImageX;
	}
	else if (wait_xCount < 0)
	{
		// マイナスなら左向きなので、2行めの先頭添字番号を引く
		waitImageX += 2;
		waitResult = waitImageX;
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

	if (MAP_HEIGHT <= (v.y + 1))
	{
		return 0;
	}
	else
	{
		if (GameManager::GetInstance()->field->mapData[v.y + 1][v.x] == 1)
		{
			return 1;
		}
		else if (GameManager::GetInstance()->field->mapData[v.y + 1][v.x + 1] == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

// プレイヤーの左を調べる(マップデータ)
int Player::CheckLeft()
{
	Vec2i v = GetMapPosition();

	if (MAP_WIDTH <= (v.x - 1))
	{
		return 0;
	}
	else
	{
		return GameManager::GetInstance()->field->mapData[v.y][v.x - 1];
	}
}

// プレイヤーの右を調べる(マップデータ)
int Player::CheckRight()
{
	Vec2i v = GetMapPosition();

	if (MAP_WIDTH <= (v.x + 1))
	{
		return 0;
	}
	else
	{
		return GameManager::GetInstance()->field->mapData[v.y][v.x + 1];
	}
}
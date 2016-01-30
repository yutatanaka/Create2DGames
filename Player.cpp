
#include "DxLib.h"
#include "GameManager.h"
#include "Field.h"
#include "Player.h"

// コンストラクタ
Player::Player() :
position(10, 684),// 初期位置
charaWidth (29),		  // 幅
charaHeight(40),		  // 高さ 
graphicHandle(),  //
xCount (),		  // 横方向のカウント数
yCount (),		  // 縦方向のカウント数
imageX (),		  // 添字用変数	
imageY (),		  // 添字用変数
result (),
move(1.0f),	      // 移動係数
jumpPower(),	  // ジャンプ力
isJump(false),	  // ジャンプしているかのフラグ(初期設定：してない状態)
isLive(true)	  // 生きているかのフラグ(初期設定：生きてる状態)
{
}

// 初期化処理
void Player::Initialize()
{
	//画像読み込み
	LoadDivGraph("res/player/charcter.png", 12, 3, 4, charaWidth, charaHeight, graphicHandle, TRUE);
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
	// 生きてれば描画
	if (isLive)
	{
		// 描画
		DrawGraph(position.x - charaWidth / 2, position.y - charaHeight / 2, graphicHandle[result], TRUE);
	}
}

// 当たり判定メソッド
void Player::IsHit(Field& field)
{
	field.distance.x = GetPosition().x + charaWidth / 2 - (field.x + field.boxWidth / 2);
	field.distance.y = GetPosition().y + charaHeight / 2 - (field.y + field.boxHeight / 2);

	if (field.distance.x >= 0) field.distance.x *= -1;
	if (field.distance.y >= 0) field.distance.y *= -1;

	if (field.distance.x < field.distance.y)
	{
		if (GetPosition().x < field.x)
		{
			position.x += field.x - (GetPosition().x + charaWidth);
		}
		else
		{
			position.x += field.x + field.boxWidth - GetPosition().x;
		}
	}
	else
	{
		if (GetPosition().y < field.y)
		{
			position.y += field.y - (GetPosition().y + field.boxHeight);
		}
		else
		{
			position.y += field.y + field.boxHeight - GetPosition().y;
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
		if (xCount > 0)
		{
			xCount = 0;
		}
		--xCount;
	}

	// →キーが押されてて、かつxCountが0以下なら0にしてから1足す
	// それ以外は1足す
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (xCount < 0)
		{
			xCount = 0;
		}
		++xCount;
	}

	// カウント数から添字を求める
	imageX = abs(xCount) % 30 / 10;
	imageY = abs(yCount) % 30 / 10;

	// xカウントがプラスなら右向きなので2行目の先頭添字番号を足す
	if (xCount > 0)
	{
		imageX += 6;
		result = imageX;
	}
	else if (xCount < 0)
	{
		// マイナスなら左向きなので、4行目の先頭添字番号を足す

		imageX += 3;
		result = imageX;
	}

	// 押されてなければカウントを0にする
	if (CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1)
	{
		xCount = 0;
	}

}

// 重力をかける処理
void Player::Gravity()
{
	// ジャンプをしてなければ重力をかけない
	if (!isJump) { return; }

		position.y += jumpPower;
		jumpPower -= 1.0f;

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
		position.y = Height - kMargin;
	}
	else if (position.y < kMargin)
	{
		position.y = kMargin;
	}
}
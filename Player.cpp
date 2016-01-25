
#include "DxLib.h"
#include "GameManager.h"
#include "Field.h"
#include "Player.h"

// コンストラクタ
Player::Player() :
position(),// 初期位置
width (29),		  // 幅
height(40),		  // 高さ 
xCount (),		  // 横方向のカウント数
yCount (),		  // 縦方向のカウント数
imageX (),		  // 添字用変数	
imageY (),		  // 添字用変数
result (),
move(64),		  // 移動係数
jumpPower(),	  // ジャンプ力
isJump(false),	  // ジャンプしているかのフラグ(初期設定：してない状態)
isLive(true)	  // 生きているかのフラグ(初期設定：生きてる状態)
{

	graphicHandle = LoadGraph("res/player/test.png");

	// 画像読み込み
	//if (-1 == LoadDivGraph("res/player/charcter.png", 12, 3, 4, 29, 40 , graphicHandle, 0))
	//{
	//	printf("エラー発生");
	//}

}


// 更新処理
void Player::Update()
{

	Input();

	Gravity();

}


// 入力処理
void Player::Input()
{

	//if (CheckHitKey(KEY_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_RIGHT) == 1)
	//{
	//	// 移動係数を0.71に設定
	//	move = 0.71;

	//}

	//　←キーが押されたら
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		//position.x -= kSpeed * move;
		position.x -= 32;
	}

	// →キーが押されたら
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		//position.x += kSpeed * move;
		position.x += 32;

	}

	// ↑キーが押されたら
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		//position.y -= kSpeed * move;
		position.y -= 32;

	}

	// ↓キーが押されたら
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		//position.y += kSpeed * move;
		position.y += 32;

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


// 描画処理
void Player::Draw()
{
	// 生きてれば描画
	if (isLive)
	{
		// 描画
		DrawGraph(position.x , position.y , graphicHandle, TRUE);
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
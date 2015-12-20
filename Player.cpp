
#include "DxLib.h"
#include  "Player.h"


// コンストラクタ
Player::Player()
{

	// 画像読み込み
	if (-1 == LoadDivGraph("res/player/charcter.png", 12, 3, 4, 29, 40, graphicHandle))
	{
		printf("エラー発生");
	}
	width = 29;
	height = 40;

	// 移動係数
	move = 1.0f;

	// 横方向と縦方向のカウント数
	xCount = 0, yCount = 0;

	// 添字用変数
	imageX = 0, imageY = 0, result = 0;

	// 初期位置
	x = 180;
	y = 400;

	isLive = true;
}


// 更新処理
void Player::Update()
{

	Draw();

	Input();

}


// 入力処理
void Player::Input()
{

	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
	{
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
		{
			// 移動係数を0.71に設定
			move = 0.71f;
		}
		else
		{
			// 斜めじゃなければ1.0に設定
			move = 1.0f;
		}
	}
	else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
	{
		move = 1.0f;
	}

	//　←キーが押されたら
	if (key[KEY_INPUT_LEFT] == 1)
	{
		x -= kSpeed * move;
	}

	// →キーが押されたら
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		x += kSpeed * move;
	}
	
	// ↑キーが押されたら
	if (key[KEY_INPUT_UP] == 1)
	{
		y -= kSpeed * move;
	}

	// ↓キーが押されたら
	if (key[KEY_INPUT_DOWN] == 1)
	{
		y += kSpeed * move;
	}


	// ←キーが押されてて、かつxCountが0以上なら0にしてから1引く
	// それ以外は1引く
	if (key[KEY_INPUT_LEFT] == 1)
	{
		if (xCount > 0)
		{
			xCount = 0;
		}
		--xCount;
	}

	// →キーが押されてて、かつxCountが0以下なら0にしてから1足す
	// それ以外は1足す
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		if (xCount < 0)
		{
			xCount = 0;
		}
		++xCount;
	}

	// ↑キーが押されてて、かつyCountが0以上なら0にしてから1引く
	// それ以外は1引く
	if (key[KEY_INPUT_UP] == 1)
	{
		if (yCount > 0)
		{
			yCount = 0;
		}
		--yCount;
	}

	// ↓キーが押されてて、かつyCountが0以下なら0にしてから1足す
	// それ以外は1足す
	if (key[KEY_INPUT_DOWN] == 1)
	{
		if (yCount < 0)
		{
			yCount = 0;
		}
		++yCount;
	}


	// カウント数から添字を求める
	imageX = abs(xCount) % 30 / 10;
	imageY = abs(yCount) % 30 / 10;

	// xカウントがプラスなら右向きなので2行目の先頭添字番号を足す
	if (xCount > 0)
	{
		imageX += 3;
		result = imageX;
	}
	else if (xCount < 0)
	{
		// マイナスなら左向きなので、4行目の先頭添字番号を足す

		imageX += 9;
		result = imageX;
	}

	// yカウントがプラスなら下向きなので、3行目の先頭添字番号を足す
	if (yCount > 0)
	{
		imageY += 6;
		result = imageY;
	}
	else if (yCount < 0)
	{
		// 1行目の先頭添字番号は0なので何もしない
		imageY += 0;
		result = imageY;
	}

	// 斜め移動の場合は横顔を優先
	if (move == 0.71f)
	{
		result = imageX;
	}

	// 押されてなければカウントを0にする
	if (key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1)
	{
		xCount = 0;
	}
	if (key[KEY_INPUT_UP] != 1 && key[KEY_INPUT_DOWN] != 1)
	{
		yCount = 0;
	}
}


// 描画処理
void Player::Draw()
{
	// 生きてれば描画
	if (isLive)
	{
		// 描画
		DrawGraph(x - width / 2, y - height / 2, graphicHandle[result], TRUE);
	}
}
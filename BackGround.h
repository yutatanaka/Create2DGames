
#pragma once

class BackGround
{
public:
	// コンストラクタ
	BackGround();

	// 初期化メソッド
	void Initialize();

	// 更新メソッド
	void Update();

	// 描画メソッド
	void Draw();

private:

	// 高さ、幅
	int x, y;

	// 格納用ハンドル
	int backGraphicHandle;

	// 10ピクセル分の余白(定数)
	const int kMargin = 10;
};
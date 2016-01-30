
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
	int height, width;

	// 格納用ハンドル
	int backGraphicHandle;

};
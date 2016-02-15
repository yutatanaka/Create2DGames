
#pragma once

class Sound
{
public:

	// コンストラクタ
	Sound();

	// デストラクタ
	~Sound();

	// 初期化処理メソッド
	void Initialize();

public:

	// ゲーム画面で
	int gameBackGroundHandle;

	// 決定ボタンなどを押したときのSE
	int dicitionSoundHandle;

	// タイトル画面で流れるBGM
	int titleBackGroundHandle;

	// クリア画面で流れるBGM
	int clearBackGroundHandle;

	// プレイヤーがジャンプモーションの時のSE
	int jumpSoundHandle;
};

extern Sound sound;
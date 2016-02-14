
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

	// 決定ボタンなどを押したときのSE
	int dicitionSoundHandle;

	// ゲーム画面で流れるBGM
	int gameMusicHandle;

	// ゲームオーバーで流れるBGM
	int gameOverMusicHandle;

	// クリア画面で流れるBGM
	int clearMusicHandle;

	// プレイヤーが待機モーションの時のSE
	int dogSoundHandle;

	// プレイヤーがジャンプモーションの時のSE
	int jumpSoundHandle;
};

extern Sound sound;
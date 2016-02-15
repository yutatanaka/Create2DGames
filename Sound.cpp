
#include "DxLib.h"
#include "Sound.h"

Sound sound;

// コンストラクタ
Sound::Sound() :
dicitionSoundHandle(0),
titleMusicHandle(0),
gameOverMusicHandle(0),
clearMusicHandle(0),
dogSoundHandle(0),
jumpSoundHandle(0)
{
}

// デストラクタ
Sound::~Sound()
{

}

// 初期化処理メソッド
void Sound::Initialize()
{
	dicitionSoundHandle = LoadSoundMem("res/sound/dicition.wav");
	titleMusicHandle = LoadSoundMem("res/sound/titleBackGround.wav");
	gameOverMusicHandle = LoadSoundMem("res/sound/gameOver.wav");
	clearMusicHandle = LoadSoundMem("res/sound/clear.wav");
	dogSoundHandle = LoadSoundMem("res/sound/dog.mp3");
	jumpSoundHandle = LoadSoundMem("res/sound/jump.mp3");

}

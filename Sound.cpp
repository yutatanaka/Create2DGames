
#include "DxLib.h"
#include "Sound.h"

Sound sound;

// �R���X�g���N�^
Sound::Sound() :
dicitionSoundHandle(0),
titleMusicHandle(0),
gameOverMusicHandle(0),
clearMusicHandle(0),
dogSoundHandle(0),
jumpSoundHandle(0)
{
}

// �f�X�g���N�^
Sound::~Sound()
{

}

// �������������\�b�h
void Sound::Initialize()
{
	dicitionSoundHandle = LoadSoundMem("res/sound/dicition.wav");
	titleMusicHandle = LoadSoundMem("res/sound/titleBackGround.wav");
	gameOverMusicHandle = LoadSoundMem("res/sound/gameOver.wav");
	clearMusicHandle = LoadSoundMem("res/sound/clear.wav");
	dogSoundHandle = LoadSoundMem("res/sound/dog.mp3");
	jumpSoundHandle = LoadSoundMem("res/sound/jump.mp3");

}

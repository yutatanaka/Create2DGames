
#include "DxLib.h"
#include "Sound.h"

Sound sound;

// �R���X�g���N�^
Sound::Sound() :
gameBackGroundHandle(0),
dicitionSoundHandle(0),
titleBackGroundHandle(0),
clearBackGroundHandle(0),
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
	gameBackGroundHandle = LoadSoundMem("res/sound/gameBackGround.mp3");
	dicitionSoundHandle = LoadSoundMem("res/sound/dicition.wav");
	titleBackGroundHandle = LoadSoundMem("res/sound/titleBackGround.wav");
	clearBackGroundHandle = LoadSoundMem("res/sound/clear.wav");
	jumpSoundHandle = LoadSoundMem("res/sound/jump.mp3");

}

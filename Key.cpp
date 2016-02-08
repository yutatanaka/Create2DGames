
#include "DxLib.h"
#include "Key.h"

// コンストラクタ
Key::Key()
{
	key[256] = { 0 };
	tmpKey[256] = { 0 };
}

// デストラクタ
Key::~Key()
{
}

// キーの入力状態を更新する
int Key::UpdateKey()
{
	// 全てのキーの入力状態を得る
	GetHitKeyStateAll(tmpKey); 

	for (int i = 0; i < 256; ++i)
	{
		if (tmpKey[i] != 0)	// i番のキーコードに対応するキーが押されていたら
		{
			key[i]++;		// 加算
		}
		else				// 押されていなければ
		{
			key[i] = 0;		// 0にする
		}
	}
	return 0;
}
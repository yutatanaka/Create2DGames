
#pragma once

class Key
{
public:

	// コンストラクタ
	Key();

	// デストラクタ
	~Key();

	// キーの入力状態を更新する
	int UpdateKey();

public:

	// キーが押されているフレーム数を格納する
	int key[256];

	// 現在のキーの入力状態を格納する
	char tmpKey[256];
};
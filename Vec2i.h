
#pragma once

class Vec2i
{
public:

	// コンストラクタ
	Vec2i()
	{
		x = y = 0;
	}

	Vec2i(int _x, int _y)
	{
		x = _x;
		y = _y;
	};

	// 自作定義 += オペレータ(演算子)
	// Vec2i += Vec2i を実装

	Vec2i operator+=(const Vec2i& _other)
	{
		return *this = Vec2i(this->x + _other.x, this->y + _other.y);
	}

	// 自作定義 * オペレータ(演算子)
	// Vec2i * int を実装
	Vec2i operator*(const int& _other)
	{
		return Vec2i(this->x * _other, this->y * _other);
	}

	// 自作定義 / オペレータ(演算子)
	// Vec2i / int を実装
	Vec2i operator/(const int& _other)
	{
		return Vec2i(this->x / _other, this->y / _other);
	}


	int x;
	int y;
};
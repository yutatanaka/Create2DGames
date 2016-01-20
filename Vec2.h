
#pragma once

class Vec2
{
public:
	
	// コンストラクタ
	Vec2()
	{
		x = y = 0;
	}

	Vec2(float _x, float _y)
	{
		x = _x;
		y = _y;
	};
	
	// 自作定義 += オペレータ(演算子)
	// Vec2 += Vec2 を実装

	Vec2 operator+=(const Vec2& _other)
	{
		return *this = Vec2(this->x + _other.x, this->y + _other.y);
	}


	// 自作定義 * オペレータ(演算子)
	// Vec2 * float を実装
	Vec2 operator*(const float& _other)
	{
		return Vec2(this->x * _other, this->y * _other);
	}

	// 自作定義 / オペレータ(演算子)
	// Vec2 / float を実装
	Vec2 operator/(const int& _other)
	{
		return Vec2(this->x / _other, this->y / _other);
	}


	float x;
	float y;
};
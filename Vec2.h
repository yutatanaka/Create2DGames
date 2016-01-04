
#pragma once

class Vec2f
{
public:
	
	// コンストラクタ
	Vec2f()
	{
		x = y = 0;
	}

	// デストラクタ
	Vec2f(float _x, float _y)
	{
		x = _x;
		y = _y;
	};

	
	// 自作定義 += オペレータ(演算子)
	// Vec2f += Vec2f を実装

	Vec2f operator+=(const Vec2f& _other)
	{
		return *this = Vec2f(this->x + _other.x, this->y + _other.y);
	}


	// 自作定義 += オペレータ(演算子)
	// Vec2f * float を実装
	Vec2f operator*(const float& _other)
	{
		return Vec2f(this->x * _other, this->y * _other);
	}


	float x;
	float y;
};
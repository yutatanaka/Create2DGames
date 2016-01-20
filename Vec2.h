
#pragma once

class Vec2
{
public:
	
	// �R���X�g���N�^
	Vec2()
	{
		x = y = 0;
	}

	Vec2(float _x, float _y)
	{
		x = _x;
		y = _y;
	};
	
	// �����` += �I�y���[�^(���Z�q)
	// Vec2 += Vec2 ������

	Vec2 operator+=(const Vec2& _other)
	{
		return *this = Vec2(this->x + _other.x, this->y + _other.y);
	}


	// �����` * �I�y���[�^(���Z�q)
	// Vec2 * float ������
	Vec2 operator*(const float& _other)
	{
		return Vec2(this->x * _other, this->y * _other);
	}

	// �����` / �I�y���[�^(���Z�q)
	// Vec2 / float ������
	Vec2 operator/(const int& _other)
	{
		return Vec2(this->x / _other, this->y / _other);
	}


	float x;
	float y;
};
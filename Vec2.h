
#pragma once

class Vec2f
{
public:
	
	// �R���X�g���N�^
	Vec2f()
	{
		x = y = 0;
	}

	// �f�X�g���N�^
	Vec2f(float _x, float _y)
	{
		x = _x;
		y = _y;
	};

	
	// �����` += �I�y���[�^(���Z�q)
	// Vec2f += Vec2f ������

	Vec2f operator+=(const Vec2f& _other)
	{
		return *this = Vec2f(this->x + _other.x, this->y + _other.y);
	}


	// �����` += �I�y���[�^(���Z�q)
	// Vec2f * float ������
	Vec2f operator*(const float& _other)
	{
		return Vec2f(this->x * _other, this->y * _other);
	}


	float x;
	float y;
};
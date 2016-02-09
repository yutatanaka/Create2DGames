
#pragma once

class Vec2i
{
public:

	// �R���X�g���N�^
	Vec2i()
	{
		x = y = 0;
	}

	Vec2i(int _x, int _y)
	{
		x = _x;
		y = _y;
	};

	// �����` += �I�y���[�^(���Z�q)
	// Vec2i += Vec2i ������

	Vec2i operator+=(const Vec2i& _other)
	{
		return *this = Vec2i(this->x + _other.x, this->y + _other.y);
	}

	// �����` * �I�y���[�^(���Z�q)
	// Vec2i * int ������
	Vec2i operator*(const int& _other)
	{
		return Vec2i(this->x * _other, this->y * _other);
	}

	// �����` / �I�y���[�^(���Z�q)
	// Vec2i / int ������
	Vec2i operator/(const int& _other)
	{
		return Vec2i(this->x / _other, this->y / _other);
	}


	int x;
	int y;
};
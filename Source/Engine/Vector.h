#pragma once
#include <Exports.h>
#include <cmath>
#include <SFML\System\Vector2.hpp>

namespace sfe
{
	template <typename T>
	class ENGINE_EXPORT Vector2
	{
	public:
		Vector2() : x(0), y(0) {}
		Vector2(T X, T Y) : x(X), y(Y) {}

		template <typename U>
		explicit Vector2(const Vector2<U>& vector) : x(static_cast<T>(U.x)), y(static_cast<T>(U.y)) {}

		template <typename U>
		explicit Vector2(const sf::Vector2<U>& vector) : x(static_cast<T>(U.x)), y(static_cast<T>(U.y)) {}

		Vector2<T>& operator=(const Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		Vector2<T>& operator=(const sf::Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		operator sf::Vector2<T>() const
		{
			return sf::Vector2<T>(x, y);
		}

		Vector2<T> operator -()
		{
			return Vector2<T>(-x, -y);
		}

		Vector2<T> operator +(const Vector2<T>& right) const
		{
			return Vector2<T>(x + right.x, y + right.x);
		}

		Vector2<T> operator -(const Vector2<T>& right) const
		{
			return Vector2<T>(x - right.x, y - right.x);
		}

		Vector2<T> operator *(const T right) const
		{
			return Vector2<T>(x * right, y * right);
		}

		Vector2<T> operator /(const T right) const
		{
			return Vector2<T>(x / right, y / right);
		}

		T operator *(const Vector2<T>& right) const
		{
			return static_cast<T>(x * right.x +  y * right.y);
		}

		bool operator ==(const Vector2<T>& right)
		{
			return (x == right.x) && (y == right.y);
		}

		bool operator !=(const Vector2<T>& right)
		{
			return !(*this == right);
		}

		Vector2<T>& operator +=(const Vector2<T>& right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}

		Vector2<T>& operator -=(const Vector2<T>& right)
		{
			x -= right.x;
			y -= right.y;
			return *this;
		}

		Vector2<T>& operator *=(T right)
		{
			x *= right;
			y *= right;
			return *this;
		}

		Vector2<T>& operator /=(T right)
		{
			x /= right;
			y /= right;
			return *this;
		}

		T SqrLength() const
		{
			return x * x + y * y;
		}

		T Length() const
		{
			return static_cast<T>(std::sqrtf(SqrLength()));
		}

		Vector2<T>& Normalize()
		{
			*this *= (1 / Length());
		}

		Vector2<T> GetNormalized()
		{
			Vector2<T> tmp(*this);
			tmp.Normalize();
			return tmp;
		}

		float AngleWith(const Vector2<T>& right)
		{
			return std::acosf(*this * right) / (Length() * right.Length());
		}

		T x;
		T y;
	};

	using Vector2f = Vector2<float>;
	using Vector2u = Vector2<unsigned int>;
	using Vector2i = Vector2<int>;
}

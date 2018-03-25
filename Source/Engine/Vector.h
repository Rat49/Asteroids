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
		Vector2()
			: x(0)
			, y(0)
		{
		}

		Vector2(T X, T Y)
			: x(X)
			, y(Y)
		{
		}

		template <typename U>
		explicit Vector2(const Vector2<U>& other)
			: x(static_cast<T>(other.x))
			, y(static_cast<T>(other.y))
		{
		}

		template <typename U>
		explicit Vector2(const sf::Vector2<U>& other)
			: x(static_cast<T>(other.x))
			, y(static_cast<T>(other.y))
		{
		}

		Vector2& operator=(const Vector2& other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		Vector2& operator=(const sf::Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		operator sf::Vector2<T>() const
		{
			return sf::Vector2<T>(x, y);
		}

		Vector2 operator -() const
		{
			return Vector2(-x, -y);
		}

		Vector2 operator +(const Vector2& right) const
		{
			return Vector2(x + right.x, y + right.x);
		}

		Vector2 operator -(const Vector2& right) const
		{
			return Vector2(x - right.x, y - right.x);
		}

		Vector2 operator *(const T right) const
		{
			return Vector2(x * right, y * right);
		}

		Vector2 operator /(const T right) const
		{
			return Vector2(x / right, y / right);
		}

		T operator *(const Vector2& right) const
		{
			return static_cast<T>(x * right.x +  y * right.y);
		}

		bool operator ==(const Vector2& right) const
		{
			return (x == right.x) && (y == right.y);
		}

		bool operator !=(const Vector2& right) const
		{
			return !(*this == right);
		}

		Vector2& operator +=(const Vector2& right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}

		Vector2& operator -=(const Vector2& right)
		{
			x -= right.x;
			y -= right.y;
			return *this;
		}

		Vector2& operator *=(T right)
		{
			x *= right;
			y *= right;
			return *this;
		}

		Vector2& operator /=(T right)
		{
			x /= right;
			y /= right;
			return *this;
		}

		T SqrLength() const
		{
			return x * x + y * y;
		}

		float Length() const
		{
			return std::sqrtf(static_cast<float>(SqrLength()));
		}

		Vector2& Normalize()
		{
			float c = (1.f / Length());
			x = static_cast<T>(std::ceilf(x * c));
			y = static_cast<T>(std::ceilf(y * c));
			return *this;
		}

		Vector2 GetNormalized() const
		{
			Vector2 tmp(*this);
			tmp.Normalize();
			return tmp;
		}

		float AngleWith(const Vector2& right) const
		{
			return std::acosf(static_cast<float>(*this * right)) / (Length() * right.Length());
		}

		T x;
		T y;
	};

	template class ENGINE_EXPORT Vector2<float>;
	template class ENGINE_EXPORT Vector2<int>;

	using Vector2f = Vector2<float>;
	using Vector2i = Vector2<int>;
}

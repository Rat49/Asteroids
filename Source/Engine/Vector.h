#pragma once
#include <Engine/Exports.h>
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace sfe
{
    template <typename T>
    class ENGINE_EXPORT Vector2
    {
    public:
        static const Vector2<T>& Zero()
        {
            static const Vector2<T> ZeroVector(0,0);
            return ZeroVector;
        }

        static const Vector2<T>& One()
        {
            static const Vector2<T> OnesVector(1,1);
            return OnesVector;
        }

        Vector2() : x(0), y(0) {}
        Vector2(T X, T Y) : x(X), y(Y) {}

        template <typename U>
        explicit Vector2(const Vector2<U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

        template <typename U>
        explicit Vector2(const sf::Vector2<U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

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

        Vector2<T> operator -() const
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

        bool operator ==(const Vector2<T>& right) const
        {
            return (x == right.x) && (y == right.y);
        }

        bool operator !=(const Vector2<T>& right) const
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
            return static_cast<T>(sqrtf(SqrLength()));
        }

        Vector2<T>& Normalize()
        {
            *this *= (1 / Length());
			return *this;
        }

        Vector2<T> GetNormalized()
        {
            Vector2<T> tmp(*this);
            tmp.Normalize();
            return tmp;
        }

        float AngleWith(const Vector2<T>& right)
        {
            return acosf(*this * right) / (Length() * right.Length());
        }

        T x;
        T y;
    };

	template <typename T>
	Vector2<T> operator -(const Vector2<T>& right)
	{
		return Vector2<T>(-right.x, -right.y);
	}

	template <typename T>
	Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x += right.x;
		left.y += right.y;
		return left;
	}

	template <typename T>
	Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		return left;
	}

	template <typename T>
	Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
	{
		Vector2<T> result(left);
		result += right;
		return result;
	}

	template <typename T>
	Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
	{
		Vector2<T> result(left);
		result -= right;
		return result;
	}

	template <typename T>
	Vector2<T>& operator *=(Vector2<T>& left, T right)
	{
		left.x *= right;
		left.y *= right;
		return left;
	}

	template <typename T>
	Vector2<T> operator *(const Vector2<T>& left, T right)
	{
		Vector2<T> result(left);
		result *= right;
		return result;
	}

	template <typename T>
	Vector2<T> operator *(T left, const Vector2<T>& right)
	{
		Vector2<T> result(right);
		result *= left;
		return result;
	}

	template <typename T>
	Vector2<T> operator /(const Vector2<T>& left, T right)
	{
		Vector2<T> result(left);
		result /= right;
		return result;
	}

	template <typename T>
	Vector2<T>& operator /=(Vector2<T>& left, T right)
	{
		left.x /= right;
		left.y /= right;
		return left;
	}

	template <typename T>
	bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
	{
		return std::abs(left.x - right.x) < 0.001
			&& std::abs(left.y - right.y) < 0.001;
	}

	template <typename T>
	bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
	{
		return !(left == right);
	}

    using Vector2f = Vector2<float>;
    using Vector2u = Vector2<unsigned int>;
    using Vector2i = Vector2<int>;
}

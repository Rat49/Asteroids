#pragma once
#include <cmath>
#include <SFML\System\Vector2.hpp>

namespace VectorMath
{
	float SqrLength(sf::Vector2f vec)
	{
		return vec.x * vec.x + vec.y * vec.y;
	}

	float Length(sf::Vector2f vec)
	{
		return std::sqrtf(SqrLength(vec));
	}

	sf::Vector2f Normalize(sf::Vector2f vec)
	{
		return vec * (1 / Length(vec));
	}

	float Dot(sf::Vector2f a, sf::Vector2f b)
	{
		return a.x * b.x + a.y + b.y;
	}

	float Angle(sf::Vector2f a, sf::Vector2f b)
	{
		return std::acosf(Dot(a, b) / (Length(a) * Length(b)));
	}
}

#pragma once
#include <Engine/Exports.h>
#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace sfe
{
	namespace VectorMath
	{
		inline float ENGINE_EXPORT SqrLength(Vector2f vec)
		{
			return vec.x * vec.x + vec.y * vec.y;
		}

		inline float ENGINE_EXPORT Length(Vector2f vec)
		{
			return std::sqrt(SqrLength(vec));
		}

		inline Vector2f ENGINE_EXPORT Normalize(Vector2f vec)
		{
			return vec * (1 / Length(vec));
		}

		inline float ENGINE_EXPORT Dot(Vector2f a, Vector2f b)
		{
			return a.x * b.x + a.y + b.y;
		}

		inline float ENGINE_EXPORT Angle(Vector2f a, Vector2f b)
		{
			return std::acos(Dot(a, b) / (Length(a) * Length(b)));
		}
	}
}
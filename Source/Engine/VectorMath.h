#pragma once
#include <Engine/Exports.h>
#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace VectorMath
{
    inline float ENGINE_EXPORT SqrLength(sf::Vector2f vec)
    {
        return vec.x * vec.x + vec.y * vec.y;
    }

    inline float ENGINE_EXPORT Length(sf::Vector2f vec)
    {
        return std::sqrt(SqrLength(vec));
    }

    inline sf::Vector2f ENGINE_EXPORT Normalize(sf::Vector2f vec)
    {
        return vec * (1 / Length(vec));
    }

    inline float ENGINE_EXPORT Dot(sf::Vector2f a, sf::Vector2f b)
    {
        return a.x * b.x + a.y + b.y;
    }

    inline float ENGINE_EXPORT Angle(sf::Vector2f a, sf::Vector2f b)
    {
        return std::acos(Dot(a, b) / (Length(a) * Length(b)));
    }
}

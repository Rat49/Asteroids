#include <Engine/LineShape.h>
#include <cassert>

namespace sf
{

    LineShape::LineShape(const Vector2f& direction)
        : m_direction(direction)
    {
    }

    void LineShape::setDirection(const Vector2f&)
    {
    }

    Vector2f LineShape::getPoint(std::size_t index) const
    {
        assert(index < getPointCount());
        return sf::Vector2f();
    }
}

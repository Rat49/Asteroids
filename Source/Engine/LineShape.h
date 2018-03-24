#pragma once
#include <Exports.h>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Shape.hpp>


namespace sf
{
    class ENGINE_EXPORT LineShape : public Shape
    {
    public:
        explicit LineShape(const Vector2f& direction = Vector2f(1, 1));

        void setDirection(const Vector2f& direction);

        const Vector2f& getDirection() const { return m_direction; }

        virtual std::size_t getPointCount() const { return 2; }

        virtual Vector2f getPoint(std::size_t index) const;

    private:
        Vector2f m_direction;
    };

} // namespace sf


////////////////////////////////////////////////////////////
/// \class sf::LineShape
/// \ingroup graphics
///
/// This class inherits all the functions of sf::Transformable
/// (position, rotation, scale, bounds, ...) as well as the
/// functions of sf::Shape (outline, color, texture, ...).
///
/// Usage example:
/// \code
/// sf::LineShape line;
/// line.setDirection(sf::Vector2f(1, 1));
/// line.setOutlineColor(sf::Color::Red);
/// line.setOutlineThickness(5);
/// line.setPosition(10, 20);
/// ...
/// window.draw(line);
/// \endcode
///
/// \see sf::Shape, sf::CircleShape, sf::ConvexShape
///
////////////////////////////////////////////////////////////

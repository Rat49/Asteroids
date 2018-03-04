#include "RenderSystem.h"
#include <SFML\Graphics.hpp>

namespace
{
	const sf::String Title = { "Asteroids" };

	sf::RenderWindow s_renderWindow;
}

RenderSystem::RenderSystem()
{
	s_renderWindow.create(sf::VideoMode::getDesktopMode(), Title, sf::Style::Fullscreen);
}

RenderSystem::~RenderSystem()
{
	s_renderWindow.close();
}

void RenderSystem::Update(float)
{
	s_renderWindow.clear();
	RaiseEvent(EventId::Render, &s_renderWindow);
	s_renderWindow.display();
}

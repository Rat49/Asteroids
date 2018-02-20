#pragma once
#include <SFML/Graphics.hpp>

class Cycle
{
public:
	Cycle() = delete;
	~Cycle() = delete;

	static Cycle& Instance();

	void AddDrawable(sf::Drawable* obj);
	void RemoveDrawable(sf::Drawable* obj);

	void AddUpdateable(Updateable* obj);
	void RemoveUpdateable(Updateable* obj);

	void Run();

private:
	sf::RenderWindow mWindow;
};


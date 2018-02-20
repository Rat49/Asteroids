#include "Cycle.h"
#include "Constants.h"

//Cycle::Cycle()
//{
//	mWindow.create(sf::VideoMode::getDesktopMode(), Const::Title, sf::Style::Fullscreen);
//}
//
//Cycle::~Cycle()
//{
//	mWindow.close();
//}

void Cycle::Run()
{
	sf::Event event;
	while (mWindow.isOpen())
	{
		if (mWindow.pollEvent(event))
		{
			//send event

			switch (event.type)
			{
			case sf::Event::EventType::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					mWindow.close();
				break;
			}
		}



		mWindow.clear();
		//rw.draw();
		mWindow.display();
	}
}

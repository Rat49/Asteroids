#pragma once
#include "UpdateMethod.h"

namespace sf { class Window; }

class GameLogic : UpdateMethod
{
public:
    GameLogic();
    ~GameLogic() override;

    void SetWindow(sf::Window* wnd) { mWindow = wnd; }
    const sf::Window* GetWindow() const { return mWindow; }

    void OnUpdate(float deltaTime) override;

private:
    sf::Window* mWindow = nullptr;
};

#pragma once
#include <Exports.h>
#include <UpdateMethod.h>

namespace sf { class Window; }

class ENGINE_EXPORT GameLogic : UpdateMethod
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

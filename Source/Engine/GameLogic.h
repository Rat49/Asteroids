#pragma once
#include <Engine/Exports.h>
#include <Engine/UpdateMethod.h>

namespace sf { class Window; }

namespace sfe
{
    class ENGINE_EXPORT GameLogic : UpdateMethod
    {
    public:
        GameLogic();
        ~GameLogic() override;

        void SetWindow(sf::Window* wnd) { mWindow = wnd; }
        const sf::Window* GetWindow() const { return mWindow; }

        void OnUpdate(float deltaTime) final override;
        virtual void CustomUpdate(float deltaTime) {}

    private:
        sf::Window* mWindow = nullptr;
    };
}

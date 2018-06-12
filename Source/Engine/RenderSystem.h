#pragma once
#include <Engine/Broadcaster.h>
#include <Engine/UpdateSystem.h>
#include <Engine/RenderMethod.h>

class RenderSystem final : public Broadcaster<RenderMethod, const sf::RenderTarget&>, UpdateMethod
{
public:
    RenderSystem();
    ~RenderSystem() override;

    void OnUpdate(float deltaTime) override;
    void NotifyAll(const sf::RenderTarget& target) override;
};

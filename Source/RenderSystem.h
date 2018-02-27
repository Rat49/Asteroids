#pragma once
#include "Broadcaster.h"
#include "UpdateSystem.h"
#include "RenderMethod.h"

class RenderSystem final : public Broadcaster<RenderMethod, const sf::RenderTarget&>, UpdateMethod
{
public:
	RenderSystem();
	~RenderSystem() override;

    void OnUpdate(float deltaTime) override;
    void NotifyAll(const sf::RenderTarget& target) override;
};

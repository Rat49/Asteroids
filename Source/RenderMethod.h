#pragma once
#include <SFML/Graphics/RenderTarget.hpp>

class RenderMethod
{
public:
    RenderMethod();
    virtual ~RenderMethod();

    virtual void OnRender(const sf::RenderTarget& data) = 0;

    bool IsRenderEnabled() const { return mRenderEnabled; }

protected:
    bool mRenderEnabled = false;
};

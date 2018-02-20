#include "Subscriber.h"
#include "Context.h"

UpdateMethod::UpdateMethod()
{
	Context::Instance().GetUpdate().AddSubscriber(EventId::Update, this);
}

UpdateMethod::~UpdateMethod()
{
	Context::Instance().GetUpdate().RemoveSubscriber(EventId::Update, this);
}

void UpdateMethod::OnNotification(EventId id, void* data)
{
	Update(*reinterpret_cast<float*>(data));
}

RenderMethod::RenderMethod()
{
	Context::Instance().GetUpdate().AddSubscriber(EventId::Render, this);
}

RenderMethod::~RenderMethod()
{
	Context::Instance().GetRender().RemoveSubscriber(EventId::Render, this);
}

void RenderMethod::OnNotification(EventId id, void* data)
{
	Render(reinterpret_cast<sf::RenderTarget*>(data));
}

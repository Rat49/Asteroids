#pragma once
#include "EventIds.h"
#include <SFML\Graphics\RenderTarget.hpp>

class Subscriber
{
public:
	virtual void OnNotification(EventId id, void* data) = 0;
};

class UpdateMethod : Subscriber
{
public:
	UpdateMethod();
	virtual ~UpdateMethod();

	void OnNotification(EventId id, void* data) override final;
	virtual void Update(float deltaTime) = 0;
};

class RenderMethod : Subscriber
{
public:
	RenderMethod();
	virtual ~RenderMethod();

	void OnNotification(EventId id, void* data) override final;
	virtual void Render(sf::RenderTarget* target) = 0;
};

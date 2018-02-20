#pragma once
#include "Observable.h"
#include "Subscriber.h"

class RenderSystem : public Observable, UpdateMethod
{
public:
	RenderSystem();
	~RenderSystem() override;

	void Update(float deltaTime) override;
};

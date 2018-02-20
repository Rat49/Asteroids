#pragma once
#include "RenderSystem.h"
#include "UpdateSystem.h"

class Context final
{
public:
	static Context& Instance()
	{
		static Context _instance;
		return _instance;
	}

	RenderSystem& GetRender()
	{
		return _render;
	}

	UpdateSystem& GetUpdate()
	{
		return _update;
	}

private:
	Context()
		: _render()
		, _update()
	{
	}

	RenderSystem _render;
	UpdateSystem _update;
};
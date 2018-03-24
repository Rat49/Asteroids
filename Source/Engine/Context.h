#pragma once
#include <Exports.h>
#include <RenderSystem.h>
#include <PhysicsSystem.h>
#include <UpdateSystem.h>
#include <EventSystem.h>
#include <InputSystem.h>
#include <GameLogic.h>

namespace Context
{
	ENGINE_EXPORT sfe::EventSystem* GetEvents();
	ENGINE_EXPORT sfe::UpdateSystem* GetUpdate();
	ENGINE_EXPORT sfe::InputSystem* GetInput();
	ENGINE_EXPORT sfe::RenderSystem* GetRender();
	ENGINE_EXPORT sfe::PhysicsSystem* GetPhysics();
}

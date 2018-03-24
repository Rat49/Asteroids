#include <Windows.h>
#include <Context.h>
#include <memory>

namespace
{
	struct
	{
		std::unique_ptr<sfe::EventSystem> Events;
		std::unique_ptr<sfe::UpdateSystem> Update;
		std::unique_ptr<sfe::InputSystem> Input;
		std::unique_ptr<sfe::RenderSystem> Render;
		std::unique_ptr<sfe::PhysicsSystem> Physics;
	} Holder;
}

ENGINE_EXPORT sfe::EventSystem* Context::GetEvents()
{
	return Holder.Events.get();
}

ENGINE_EXPORT sfe::UpdateSystem* Context::GetUpdate()
{
	return Holder.Update.get();
}

ENGINE_EXPORT sfe::InputSystem* Context::GetInput()
{
	return Holder.Input.get();
}

ENGINE_EXPORT sfe::RenderSystem* Context::GetRender()
{
	return Holder.Render.get();
}

ENGINE_EXPORT sfe::PhysicsSystem* Context::GetPhysics()
{
	return Holder.Physics.get();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		Holder.Events = std::make_unique<sfe::EventSystem>();
		Holder.Update = std::make_unique<sfe::UpdateSystem>();
		Holder.Input = std::make_unique<sfe::InputSystem>();
		Holder.Render = std::make_unique<sfe::RenderSystem>();
		Holder.Physics = std::make_unique<sfe::PhysicsSystem>();
		break;
    case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
    return TRUE;
}

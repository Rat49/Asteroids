#pragma once
#include <RenderSystem.h>
#include <PhysicsSystem.h>
#include <UpdateSystem.h>
#include <EventSystem.h>
#include <InputSystem.h>
#include <GameLogic.h>
#include <memory>

class Context final
{
public:
	static Context& Instance()
	{
		static Context _instance;

        if (!_instance.mInitialized)
            _instance.Setup();

		return _instance;
	}

    EventSystem* GetEvents()
    {
        return mEvents.get();
    }

    UpdateSystem* GetUpdate()
    {
        return mUpdate.get();
    }

    InputSystem* GetInput()
    {
        return mInput.get();
    }

    GameLogic* GetLogic()
    {
        return mLogic.get();
    }
    
    RenderSystem* GetRender()
	{
		return mRender.get();
	}

    PhysicsSystem* GetPhysics()
    {
        return mPhysics.get();
    }

private:
    Context()
	{
	}

    void Setup()
    {
        mInitialized = true;
        mEvents = std::make_unique<EventSystem>();
        mUpdate = std::make_unique<UpdateSystem>();
        mInput = std::make_unique<InputSystem>();
        mLogic = std::make_unique<GameLogic>();
        mRender = std::make_unique<RenderSystem>();
        mPhysics = std::make_unique<PhysicsSystem>();
    }

    std::unique_ptr<EventSystem> mEvents;
    std::unique_ptr<UpdateSystem> mUpdate;
    std::unique_ptr<InputSystem> mInput;
    std::unique_ptr<GameLogic> mLogic;
    std::unique_ptr<RenderSystem> mRender;
    std::unique_ptr<PhysicsSystem> mPhysics;
    bool mInitialized = false;
};
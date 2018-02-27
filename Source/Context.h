#pragma once
#include "RenderSystem.h"
#include "UpdateSystem.h"
#include "EventSystem.h"
#include "InputSystem.h"
#include "GameLogic.h"
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

	RenderSystem* GetRender()
	{
		return mRender.get();
	}

	UpdateSystem* GetUpdate()
	{
		return mUpdate.get();
	}

    EventSystem* GetEvents()
    {
        return mEvents.get();
    }

    GameLogic* GetLogic()
    {
        return mLogic.get();
    }

    InputSystem* GetInput()
    {
        return mInput.get();
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
    }

    std::unique_ptr<EventSystem> mEvents;
    std::unique_ptr<UpdateSystem> mUpdate;
    std::unique_ptr<InputSystem> mInput;
    std::unique_ptr<GameLogic> mLogic;
    std::unique_ptr<RenderSystem> mRender;
    bool mInitialized = false;
};
#pragma once
#include "EventIds.h"

class EventMethod
{
public:
	virtual void OnEvent(const std::pair<EventId, void*>& data) = 0;

    bool IsEventsEnabled() const { return mEventsEnabled; }

protected:
    bool mEventsEnabled = true;
};

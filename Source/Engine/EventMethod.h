#pragma once
#include <Exports.h>
#include <EventIds.h>

class ENGINE_EXPORT EventMethod
{
public:
	virtual void OnEvent(const std::pair<EventID, void*>& data) = 0;

    bool IsEventsEnabled() const { return mEventsEnabled; }

protected:
    bool mEventsEnabled = true;
};

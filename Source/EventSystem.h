#pragma once
#include "Broadcaster.h"
#include "EventMethod.h"

class EventCaster : public Broadcaster<EventMethod, const std::pair<EventId, void*>&>
{
public:
    void NotifyAll(const std::pair<EventId, void*>& data) override;
};

class EventSystem : public MultiBroadcaster<EventMethod, const std::pair<EventId, void*>&, EventCaster>
{
public:
    void Notify(EventId id, void* data);
};

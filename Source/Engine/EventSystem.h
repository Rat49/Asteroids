#pragma once
#include <Exports.h>
#include <Broadcaster.h>
#include <EventMethod.h>

class ENGINE_EXPORT EventCaster : public Broadcaster<EventMethod, const std::pair<EventID, void*>&>
{
public:
    void NotifyAll(const std::pair<EventID, void*>& data) override;
};

class ENGINE_EXPORT EventSystem : public MultiBroadcaster<EventMethod, const std::pair<EventID, void*>&, EventCaster>
{
public:
    void Notify(EventID id, void* data);
};

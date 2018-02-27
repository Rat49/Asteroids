#include "EventSystem.h"
#include <utility>

void EventCaster::NotifyAll(const std::pair<EventId, void*>& data)
{
    for (auto& receiver : mReceivers)
    {
        if (receiver->IsEventsEnabled())
        {
            receiver->OnEvent(data);
        }
    }
}

void EventSystem::Notify(EventId id, void* data)
{
    NotifyAll(id, std::make_pair(id, data));
}

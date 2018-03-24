#include <EventSystem.h>
#include <utility>

using namespace sfe;

void EventCaster::NotifyAll(const std::pair<EventID, void*>& data)
{
    for (auto& receiver : mReceivers)
    {
        if (receiver->IsEventsEnabled())
        {
            receiver->OnEvent(data);
        }
    }
}

EventSystem::EventSystem()
	: MultiBroadcaster(256)
{
}

void EventSystem::Notify(EventID id, void* data)
{
    NotifyAll(id, std::make_pair(id, data));
}

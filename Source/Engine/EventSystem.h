#pragma once
#include <Engine/Exports.h>
#include <Engine/Broadcaster.h>
#include <Engine/EventMethod.h>

namespace sfe
{
    class ENGINE_EXPORT EventCaster : public Broadcaster<EventMethod, const std::pair<EventID, void*>&>
    {
    public:
        void NotifyAll(const std::pair<EventID, void*>& data) override;
    };

    class ENGINE_EXPORT EventSystem : public MultiBroadcaster<EventMethod, const std::pair<EventID, void*>&, EventCaster>
    {
    public:
        EventSystem();
        void Notify(EventID id, void* data);
    };
}

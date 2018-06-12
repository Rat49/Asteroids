#pragma once
#include <Engine/EventIds.h>
#include <vector>
#include <algorithm>

template<typename Method, typename Data>
class Broadcaster
{
public:
    Broadcaster() {}

    virtual ~Broadcaster() {}

    void AddReceiver(Method* receiver)
    {
        if (std::find(mReceivers.cbegin(), mReceivers.cend(), receiver) != mReceivers.cend())
        {
            //already exists
            return;
        }

        mReceivers.push_back(receiver);
    }

    void RemoveReceiver(Method* receiver)
    {
        const auto it = std::find(mReceivers.cbegin(), mReceivers.cend(), receiver);
        if (it == mReceivers.cend())
        {
            //not exist
            return;
        }

        mReceivers.erase(it);

    }

    virtual void NotifyAll(Data data) = 0;

protected:
    std::vector<Method*> mReceivers;
};

template<typename Method, typename Data, typename Caster = Broadcaster<Method, Data>>
class MultiBroadcaster
{
public:
    MultiBroadcaster(uint32_t maxEventsCount) : mReceivers(maxEventsCount) {}
    virtual ~MultiBroadcaster() {}

    void AddReceiver(EventID id, Method* receiver)
    {
        if (id == EID::Invalid)
        {
            //invalid event id
            return;
        }

        mReceivers[id].AddReceiver(receiver);
    }

    void RemoveReceiver(EventID id, Method* receiver)
    {
        if (id == EID::Invalid)
        {
            //invalid event id
            return;
        }

        mReceivers[id].RemoveReceiver(receiver);
    }

    void NotifyAll(EventID id, Data data)
    {
        if (id == EID::Invalid)
        {
            //invalid event id
            return;
        }

        mReceivers[id].NotifyAll(data);
    }

protected:
    std::vector< Caster > mReceivers;
};

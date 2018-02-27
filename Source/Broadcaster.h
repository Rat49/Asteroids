#pragma once
#include <vector>
#include <algorithm>
#include "EventIds.h"

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
    MultiBroadcaster() : mReceivers(static_cast<int>(EventId::MaxEvent)) {}
    virtual ~MultiBroadcaster() {}

    void AddReceiver(EventId id, Method* receiver)
    {
        if (id == EventId::Invalid)
        {
            //invalid event id
            return;
        }

        mReceivers[static_cast<int>(id)].AddReceiver(receiver);
    }

    void RemoveReceiver(EventId id, Method* receiver)
    {
        if (id == EventId::Invalid)
        {
            //invalid event id
            return;
        }

        mReceivers[static_cast<int>(id)].RemoveReceiver(receiver);
    }

    void NotifyAll(EventId id, Data data)
    {
        if (id == EventId::Invalid)
        {
            //invalid event id
            return;
        }

        mReceivers[static_cast<int>(id)].NotifyAll(data);
    }

protected:
    std::vector< Caster > mReceivers;
};

#include "Observable.h"
#include "Subscriber.h"
#include <algorithm>

Observable::Observable()
	: m_subscribers(static_cast<int>(EventId::MaxEvent))
{
}

Observable::~Observable()
{
}

void Observable::AddSubscriber(EventId id, Subscriber* subscriber)
{
	if (id == EventId::Invalid)
	{
		return;
	}

	auto& subscribersOnEvent = m_subscribers[static_cast<int>(id)];
	if (std::find(subscribersOnEvent.cbegin(), subscribersOnEvent.cend(), subscriber) != subscribersOnEvent.cend())
	{
		return;
	}

	subscribersOnEvent.push_back(subscriber);
}

void Observable::RemoveSubscriber(EventId id, Subscriber* subscriber)
{
	if (id == EventId::Invalid)
	{
		return;
	}

	auto& subscribersOnEvent = m_subscribers[static_cast<int>(id)];
	const auto it = std::find(subscribersOnEvent.cbegin(), subscribersOnEvent.cend(), subscriber);
	if (it == subscribersOnEvent.cend())
	{
		return;
	}

	subscribersOnEvent.erase(it);
}

void Observable::RaiseEvent(EventId id, void* data)
{
	if (id == EventId::Invalid)
	{
		return;
	}

	for (auto subsciber : m_subscribers[static_cast<int>(id)])
	{
		subsciber->OnNotification(id, data);
	}
}


#pragma once
#include <vector>
#include "EventIds.h"

class Subscriber;

class Observable
{
public:
	Observable();
	virtual ~Observable();

	void AddSubscriber(EventId id, Subscriber* subscriber);
	void RemoveSubscriber(EventId id, Subscriber* subscriber);
	void RaiseEvent(EventId id, void* data);

protected:
	std::vector< std::vector<Subscriber*> > m_subscribers;
};

#pragma once

enum class EventId : int
{
	Invalid = -1,
	Broadcast,
	Render,
	Update,

	MaxEvent
};

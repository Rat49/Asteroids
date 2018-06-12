#pragma once

enum class EventId : int
{
    Invalid = -1,
    System,
    Render,
    Update,

    Close,

    MaxEvent
};

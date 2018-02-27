#pragma once
#include "Broadcaster.h"
#include "UpdateMethod.h"
#include "EventMethod.h"

class UpdateSystem : public Broadcaster<UpdateMethod, float>, EventMethod
{
public:
    UpdateSystem();
    ~UpdateSystem() override;

    void FixFrequency(int framesPerSecond);
	void Run();

    void NotifyAll(float data) override;
    void OnEvent(const std::pair<EventId, void*>& data) override;

private:
    float mSecBeforeUpdate = 0.f;
    bool mStopCycle = false;
};

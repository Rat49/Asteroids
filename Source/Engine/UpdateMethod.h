#pragma once

class UpdateMethod
{
public:
    UpdateMethod();
    virtual ~UpdateMethod();

    virtual void OnUpdate(float deltaTime) = 0;

    bool IsUpdateEnabled() const { return mUpdateEnabled; }

protected:
    bool mUpdateEnabled = true;
};

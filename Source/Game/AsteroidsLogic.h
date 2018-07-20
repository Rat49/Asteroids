#pragma once
#include <Engine/Context.h>
#include <Engine/MemoryPool.h>
#include <Game/Ship.h>
#include <Game/Rock.h>
#include <Game/Bullet.h>

class AsteroidsLogic : public sfe::GameLogic
{
public:
    AsteroidsLogic();
    ~AsteroidsLogic();

    void Start();
    void CustomUpdate(float deltaTime) override;

private:
    std::unique_ptr<Ship> mPlayer;
    sfe::MemoryPool<Rock, 10> mRocks;
    sfe::MemoryPool<Bullet, 8> mBullets;
};

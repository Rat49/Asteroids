#include <Game/AsteroidsLogic.h>

AsteroidsLogic::AsteroidsLogic()
    : GameLogic()
{
}

AsteroidsLogic::~AsteroidsLogic()
{
}

void AsteroidsLogic::Start()
{
    mPlayer = std::make_unique<Ship>();
    auto r1 = mRocks.Get();
    mRocks.Put(r1);
}

void AsteroidsLogic::CustomUpdate(float deltaTime)
{
}

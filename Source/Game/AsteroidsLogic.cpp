#include <Game/AsteroidsLogic.h>
#include <Game/InputGameAction.h>


namespace
{
    int32_t GetActionValue(int32_t actionId)
    {
        return sfe::Context::Instance().GetInput()->IsPressed(actionId) ? 1 : 0;
    }

    sfe::Vector2f GetMovementVec()
    {
        return sfe::Vector2f(
            static_cast<float>(GetActionValue(GameAction::MoveRight) - GetActionValue(GameAction::MoveLeft)),
			static_cast<float>(GetActionValue(GameAction::MoveDown) - GetActionValue(GameAction::MoveUp)));
    }
}

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

void AsteroidsLogic::CustomUpdate(float)
{
    mPlayer->SetDirection(GetMovementVec());
    if (sfe::Context::Instance().GetInput()->GetState(GameAction::Shoot) == sfe::ActionState::JustEntered)
    {
        auto bullet = mBullets.Get();
        if (bullet)
        {
            auto speed = mPlayer->GetDirection().Normalize() * 500.f;
            bullet->Start(mPlayer->GetPosition(), speed, 500.f);
        }
    }

    for(const auto& b : mBullets.GetBusyObjects())
    {
        if(b && !b->IsFlying())
        {
            mBullets.Put(b);
        }
    }
}

#include <AsteroidsLogic.h>

void AsteroidsLogic::Setup()
{
	mPlayer = std::make_unique<Ship>();
	mRock = std::make_unique<Rock>();
}

void AsteroidsLogic::CustomUpdate(float deltaTime)
{
	
}

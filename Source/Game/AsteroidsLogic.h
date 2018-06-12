#pragma once
#include <Context.h>
#include <Ship.h>
#include <Rock.h>
#include <Bullet.h>
#include <memory>

class AsteroidsLogic : public sfe::GameLogic
{
public:
	void Setup();
	void CustomUpdate(float deltaTime) override;

private:
	std::unique_ptr<Ship> mPlayer;
	std::unique_ptr<Rock> mRock;
	//rocks should be in pool
	//bullets should be in pool
};

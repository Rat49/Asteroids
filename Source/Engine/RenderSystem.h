#pragma once
#include <Exports.h>
#include <Broadcaster.h>
#include <UpdateSystem.h>
#include <RenderMethod.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>


namespace sfe
{
	class ENGINE_EXPORT RenderSystem final : public Broadcaster<RenderMethod, const sf::RenderTarget&>, UpdateMethod
	{
	public:
		RenderSystem();
		~RenderSystem() override;

		void OnUpdate(float deltaTime) override;
		void NotifyAll(const sf::RenderTarget& target) override;

		void SetWindow(std::shared_ptr<sf::RenderWindow> wnd);
		std::shared_ptr<sf::RenderWindow> GetWindow() const { return mRenderWindow; }

	private:
		std::shared_ptr<sf::RenderWindow> mRenderWindow;
	};
}
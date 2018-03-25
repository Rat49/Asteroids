#pragma once
#include <Exports.h>
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfe
{
	class ENGINE_EXPORT RenderMethod
	{
	public:
		RenderMethod();
		virtual ~RenderMethod();

		virtual void OnRender(sf::RenderTarget& data) = 0;

		bool IsRenderEnabled() const { return mRenderEnabled; }

	protected:
		bool mRenderEnabled = true;
	};
}

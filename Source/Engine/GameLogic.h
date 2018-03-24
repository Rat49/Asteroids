#pragma once
#include <Exports.h>
#include <UpdateMethod.h>

namespace sf { class Window; }

namespace sfe
{
	class ENGINE_EXPORT GameLogic : UpdateMethod
	{
	public:
		GameLogic();
		~GameLogic() override;

		void OnUpdate(float deltaTime) override;

	protected:
		virtual void CustomUpdate(float deltaTime);
	};
}

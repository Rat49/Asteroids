#pragma once
#include <cstdint>

namespace sfe
{
	using EventID = uint32_t;

	struct EID
	{
		static constexpr EventID Invalid = 0xFFFFFFFF;
		static constexpr EventID System = 0;

		static constexpr EventID Render = 1;
		static constexpr EventID Update = 2;

		static constexpr EventID WinClose = 10;
	};
}
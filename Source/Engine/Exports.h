#pragma once

#ifdef ENGINE_LIB
	#define ENGINE_EXPORT __declspec(dllexport)
#else
	#define ENGINE_EXPORT __declspec(dllimport)
#endif

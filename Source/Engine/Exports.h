#pragma once

#ifdef ENGINE_STATIC
#	define ENGINE_EXPORT
#else
#	ifdef ENGINE_LIB
#		ifdef _WINDOWS
#			define ENGINE_EXPORT __declspec(dllexport)
#		else
#			define ENGINE_EXPORT __attribute__ ((visibility("default")))
#		endif
#	else
#		ifdef _WINDOWS
#			define ENGINE_EXPORT __declspec(dllimport)
#		else
#			define ENGINE_EXPORT __attribute__ ((visibility("default")))
#		endif
#	endif
#endif

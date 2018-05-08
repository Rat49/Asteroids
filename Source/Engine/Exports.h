#pragma once

#ifdef _WINDOWS
#   ifdef ENGINE_LIB
#       define ENGINE_EXPORT __declspec(dllexport)
#   else
#       define ENGINE_EXPORT __declspec(dllimport)
#   endif
#else
#   ifdef ENGINE_LIB
#       define ENGINE_EXPORT __attribute__ ((visibility("default")))
#   else
#       define ENGINE_EXPORT __attribute__ ((visibility("default")))
#   endif
#endif

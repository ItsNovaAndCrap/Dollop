#pragma once

#ifdef DP_PLATFORM_WINDOWS
	#ifdef DP_BUILD_DLL
		#define DOLLOP_API __declspec(dllexport)
	#else
		#define DOLLOP_API __declspec(dllexport)
	#endif
#else
	#error Dollop only supports Windows!
#endif
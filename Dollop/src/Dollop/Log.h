#pragma once

#include "Core.h"
#include "spdlog\spdlog.h"

namespace Dollop {

	class DOLLOP_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		static std::shared_ptr<spdlog::logger>& GetClientLogger();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define DP_CORE_TRACE(...)		::Dollop::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DP_CORE_INFO(...)		::Dollop::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DP_CORE_WARN(...)		::Dollop::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DP_CORE_ERROR(...)		::Dollop::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DP_CORE_FATAL(...)		::Dollop::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define DP_TRACE(...)		::Dollop::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DP_INFO(...)		::Dollop::Log::GetClientLogger()->info(__VA_ARGS__)
#define DP_WARN(...)		::Dollop::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DP_ERROR(...)		::Dollop::Log::GetClientLogger()->error(__VA_ARGS__)
#define DP_FATAL(...)		::Dollop::Log::GetClientLogger()->critical(__VA_ARGS__)

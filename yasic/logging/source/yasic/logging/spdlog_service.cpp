// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT

#include "yasic/logging/spdlog_service.h"

#include "yasic/logging/log_service.h"

#include <memory>
#include <string>

#include "spdlog/common.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"

#ifdef WIN32
  #include "spdlog/sinks/msvc_sink.h"
  #include "spdlog/sinks/wincolor_sink.h"
#else
  #include "spdlog/sinks/stdout_color_sinks.h"
#endif

#include <vector>

namespace yasic::logging
{
spdlog_service::spdlog_service(std::string const& context)
{
	std::vector<spdlog::sink_ptr> const sinks{
	    std::make_shared<spdlog::sinks::basic_file_sink_mt>(context + ".log"),
#ifdef WIN32
	    std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>(),
	    std::make_shared<spdlog::sinks::msvc_sink_mt>(),
#else
	    std::make_shared<spdlog::sinks::stdout_color_sink_mt>(),
#endif
	};

	m_logger =
	    std::make_shared<spdlog::logger>(context, sinks.begin(), sinks.end());
}

void spdlog_service::log_impl(log_level const level, std::string const& message)
{
	// NOLINTNEXTLINE(clang-diagnostic-switch-default)
	switch (level)
	{
		using enum log_level;
	case trace: m_logger->trace(message); break;
	case debug: m_logger->debug(message); break;
	case info: m_logger->info(message); break;
	case warn: m_logger->warn(message); break;
	case error: m_logger->error(message); break;
	case fatal: m_logger->critical(message); break;
	}
}

void spdlog_service::set_level(log_level const log_level)
{
	// NOLINTNEXTLINE(clang-diagnostic-switch-default)
	switch (log_level)
	{
		using enum log_level;
	case trace: m_logger->set_level(spdlog::level::trace); break;
	case debug: m_logger->set_level(spdlog::level::debug); break;
	case info: m_logger->set_level(spdlog::level::info); break;
	case warn: m_logger->set_level(spdlog::level::warn); break;
	case error: m_logger->set_level(spdlog::level::err); break;
	case fatal: m_logger->set_level(spdlog::level::critical); break;
	}
}
} // namespace yasic::logging

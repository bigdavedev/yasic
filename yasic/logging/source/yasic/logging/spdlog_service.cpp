// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT

#include "yasic/logging/spdlog_service.h"

#include "yasic/logging/log_service.h"

#include "spdlog/common.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#ifdef WIN32
  #include "spdlog/sinks/msvc_sink.h"
  #include "spdlog/sinks/wincolor_sink.h"
#else
  #include "spdlog/sinks/stdout_color_sinks.h"
#endif

#include <memory>
#include <string>
#include <vector>

namespace yasic::logging
{
spdlog_service::spdlog_service(std::string_view const log_file_name)
    : m_shared_sinks{
          std::make_shared<spdlog::sinks::basic_file_sink_mt>(
              log_file_name.data(),
              true),
#ifdef WIN32
          std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>(),
          std::make_shared<spdlog::sinks::msvc_sink_mt>(),
#else
          std::make_shared<spdlog::sinks::stdout_color_sink_mt>()
#endif
      }
{}

void spdlog_service::log_impl(context const&     ctx,
                              log_level const    level,
                              std::string const& message)
{
	if (auto const logger = m_logger_registry.find(ctx.name());
	    logger != m_logger_registry.end())
	{
		// NOLINTNEXTLINE(clang-diagnostic-switch-default)
		switch (level)
		{
			using enum log_level;
		case trace: logger->second->trace(message); break;
		case debug: logger->second->debug(message); break;
		case info: logger->second->info(message); break;
		case warn: logger->second->warn(message); break;
		case error: logger->second->error(message); break;
		case fatal: logger->second->critical(message); break;
		}
	}
}

void spdlog_service::set_level(context const& ctx, log_level const log_level)
{
	if (auto const logger = m_logger_registry.find(ctx.name());
	    logger != m_logger_registry.end())
	{
		// NOLINTNEXTLINE(clang-diagnostic-switch-default)
		switch (log_level)
		{
			using enum log_level;
		case trace: logger->second->set_level(spdlog::level::trace); break;
		case debug: logger->second->set_level(spdlog::level::debug); break;
		case info: logger->second->set_level(spdlog::level::info); break;
		case warn: logger->second->set_level(spdlog::level::warn); break;
		case error: logger->second->set_level(spdlog::level::err); break;
		case fatal: logger->second->set_level(spdlog::level::critical); break;
		}
	}
}

void spdlog_service::add_sink(context const&          ctx,
                              spdlog::sink_ptr const& sink) const
{
	if (auto const logger = m_logger_registry.find(ctx.name());
	    logger != m_logger_registry.end())
	{
		logger->second->sinks().emplace_back(sink);
	}
}

logging_service::context spdlog_service::create_context(std::string const& name)
{
	if (!m_logger_registry.contains(name))
	{
		m_logger_registry
		    .try_emplace(name, std::make_shared<spdlog::logger>(name))
		    .first->second->sinks()
		    .append_range(m_shared_sinks);
	}
	return context{name};
}
} // namespace yasic::logging

// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT

#include "yasic/logging/spdlog_service.h"
#include "yasic/logging/log_service.h"

#include "spdlog/logger.h"
#include "spdlog/common.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <string>
#include <memory>

namespace yasic::logging
{

spdlog_service::spdlog_service(std::string const& context)
	: m_logger{std::make_shared<spdlog::logger>(
	      context, std::make_shared<spdlog::sinks::stdout_color_sink_mt>())}
{}

void spdlog_service::log_impl(log_level const level, std::string const& message)
{
	// NOLINTNEXTLINE(clang-diagnostic-switch-default)
	switch (level)
	{
	case log_level::trace:
		m_logger->trace(message);
		break;
	case log_level::debug:
		m_logger->debug(message);
		break;
	case log_level::info:
		m_logger->info(message);
		break;
	case log_level::warn:
		m_logger->warn(message);
		break;
	case log_level::error:
		m_logger->error(message);
		break;
	case log_level::fatal:
		m_logger->critical(message);
		break;
	}
}

void spdlog_service::set_level(log_level const log_level)
{
	// NOLINTNEXTLINE(clang-diagnostic-switch-default)
	switch (log_level)
	{
	case log_level::trace:
		m_logger->set_level(spdlog::level::trace);
		break;
	case log_level::debug:
		m_logger->set_level(spdlog::level::debug);
		break;
	case log_level::info:
		m_logger->set_level(spdlog::level::info);
		break;
	case log_level::warn:
		m_logger->set_level(spdlog::level::warn);
		break;
	case log_level::error:
		m_logger->set_level(spdlog::level::err);
		break;
	case log_level::fatal:
		m_logger->set_level(spdlog::level::critical);
		break;
	}
}
} // namespace yasic::logging

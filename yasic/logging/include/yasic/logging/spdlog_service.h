// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#pragma once

#include "yasic/logging/log_service.h"
#include "yasic/service/service.h"

#include "spdlog/logger.h"
#include "spdlog/sinks/base_sink.h"

#include <memory>
#include <string>
#include <unordered_map>

namespace yasic::logging
{
/**
 * A logging service that uses the spdlog library for logging.
 *
 * This service provides a way to create logging contexts and log messages
 * with different log levels. It supports multiple sinks, including file and
 * console sinks.
 */
class spdlog_service : public yasic::service::service<logging_service>
{
public:
	/**
	 * Initializes the logging service with standard output and a file sink.
	 *
	 * @param log_file_name Name of the log file to write to.
	 */
	explicit spdlog_service(std::string_view log_file_name);

	/**
	 * @copydoc {yasic::logging::logging_service::set_level}
	 */
	void set_level(context const& ctx, log_level log_level) override;

	/**
	 * @copydoc{yasic::logging::logging_service::create_context}
	 */
	context create_context(std::string_view name) override;

	/**
	 * Add a sink to the logging service.
	 *
	 * @param ctx Context to which the sink will be added.
	 * @param sink Sink to add to the logging service.
	 */
	void add_sink(context const& ctx, spdlog::sink_ptr const& sink) const;

private:
	void log_impl(context const&     ctx,
	              log_level          level,
	              std::string const& message) override;

	struct string_hasher final
	{
		using is_transparent = void;

		std::size_t operator()(std::string_view const string) const
		{
			constexpr std::hash<std::string_view> hasher{};
			return hasher(string);
		}
	};

	std::unordered_map<std::string,
	                   std::shared_ptr<spdlog::logger>,
	                   string_hasher,
	                   std::equal_to<>>
	    m_logger_registry;

	std::vector<spdlog::sink_ptr> m_shared_sinks;
};
} // namespace yasic::logging

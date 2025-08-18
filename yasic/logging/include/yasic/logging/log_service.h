// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#pragma once

#include "yasic/service/service.h"

#include "fmt/format.h"

#include <string>
#include <string_view>

namespace yasic::logging
{
enum class log_level
{
	trace,
	debug,
	info,
	warn,
	error,
	fatal
};

class logging_service : public yasic::service::service_base
{
public:
	class context final
	{
		std::string m_name;

	public:
		explicit context(std::string_view const name)
		    : m_name{name}
		{}

		context() = delete;

		[[nodiscard]]
		std::string_view name() const
		{
			return m_name;
		}
	};

	/**
	 * Log a message with the specified log level.
	 *
	 * @param ctx The logging context to use.
	 * @param level The log level to use.
	 * @param msg The formatted message to log.
	 * @param args Any arguments for the formatted string.
	 */
	template <typename... Args>
	void log(context const&                ctx,
	         log_level const               level,
	         fmt::format_string<Args...>&& msg,
	         Args&&... args)
	{
		log_impl(ctx,
		         level,
		         fmt::format(std::move(msg), std::forward<Args>(args)...));
	}

	/**
	 * Set the minimum log level for a specific context.
	 *
	 * @param ctx Context for which to set the log level.
	 * @param log_level Level to set for the context.
	 */
	virtual void set_level(context const& ctx, log_level log_level) = 0;

	/**
	 * Create a new logging context with the specified name.
	 *
	 * In order to log messages, you must first create a context.
	 *
	 * @param name Name of the context to create.
	 * @return A new logging context.
	 */
	virtual context create_context(std::string_view name) = 0;

private:
	virtual void log_impl(context const&     ctx,
	                      log_level          level,
	                      std::string const& message) = 0;
};
} // namespace yasic::logging

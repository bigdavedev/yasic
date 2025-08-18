// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#pragma once

#include "yasic/service/service.h"

#include <string>

#include "fmt/format.h"

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
		std::string m_name{};

	public:
		explicit context(std::string const& name)
		    : m_name(name)
		{}

		context() = delete;

		std::string_view name() const
		{
			return m_name;
		}
	};

	/**
	 * Log a message with the specified log level.
	 *
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

	virtual void set_level(context const& ctx, log_level log_level) = 0;

	virtual context create_context(std::string const& name) = 0;

private:
	virtual void log_impl(context const&     ctx,
	                      log_level          level,
	                      std::string const& message) = 0;
};
} // namespace yasic::logging

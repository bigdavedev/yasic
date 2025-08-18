// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#pragma once

#include "yasic/logging/log_service.h"
#include "yasic/service/service.h"

#include <string>

namespace yasic::logging
{
/**
 * Null logger service that does nothing.
 *
 * This service is used when no logging is required.
 */
class null_log_service : public yasic::service::service<logging_service>
{
public:
	null_log_service() = default;

	void set_level(log_level const /*log_level*/) override
	{
		// Do nothing
	}

private:
	void log_impl(log_level const /*level*/, std::string const& /*message*/) override
	{
		// Do nothing
	}
};
} // namespace yasic::logging

// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#pragma once

#include "yasic/logging/log_service.h"
#include "yasic/service/service.h"

#include <memory>
#include <string>

#include "spdlog/logger.h"

namespace yasic::logging
{
class spdlog_service : public yasic::service::service<logging_service>
{
public:
	explicit spdlog_service(std::string const& context);

	void set_level(log_level log_level) override;

private:
	void log_impl(log_level level, std::string const& message) override;

	std::shared_ptr<spdlog::logger> m_logger;
};
} // namespace yasic::logging

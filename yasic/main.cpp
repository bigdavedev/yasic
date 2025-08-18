// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#include "yasic/logging/log_service.h"
#include "yasic/logging/spdlog_service.h"
#include "yasic/service/service_locator.h"

#include "SDL3/SDL_error.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_main.h"

#include <memory>

int main(int argc, char* argv[])
{
	static_cast<void>(argc);
	static_cast<void>(argv);

	auto service_locator = yasic::service::service_locator{};

	service_locator.register_service(
	    std::make_shared<yasic::logging::spdlog_service>("Yasic.log"));
	auto const logging_service =
	    service_locator.get_service<yasic::logging::logging_service>();

	auto const main_log_context = logging_service->create_context("main");

	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO))
	{
		service_locator.get_service<yasic::logging::logging_service>()->log(
		    main_log_context,
		    yasic::logging::log_level::fatal,
		    "Failed to initialize SDL: {}",
		    SDL_GetError());
		return -1;
	}

	SDL_Quit();

	return 0;
}

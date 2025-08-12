// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_main.h"

int main(int argc, char* argv[])
{
	static_cast<void>(argc);
	static_cast<void>(argv);

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO);

	SDL_Quit();

	return 0;
}

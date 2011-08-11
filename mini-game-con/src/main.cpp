#include <SDL.h>
#include <SDL_assert.h>

#include "debug.h"

int main() {
	SDL_Log("%s", "start programm");
	debug_init();
	SDL_Log("%s", "debug init");
	int result = SDL_Init(SDL_INIT_EVERYTHING);
	SDL_assert_release(result >= 0);
	SDL_Log("%s", "sdl init");
	SDL_Surface * screen = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
	SDL_assert(NULL != screen);
	SDL_Log("%s", "create window");
	bool loop = true;
	while (loop) {
		SDL_Event event = {0};
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					loop = false;
				} else if (event.key.keysym.sym == SDLK_SPACE)
				{
					int * ptr = 0;
					*ptr = 0; // Make crush! Test debug print stack
				}
			} else if (event.type == SDL_WINDOWEVENT and event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				loop = false;
			}
		}
		SDL_Delay(0); // do not use all CPU
	}

	SDL_FreeSurface(screen);
	SDL_Log("%s", "destroy window");
	SDL_Quit();

	return EXIT_SUCCESS;
}

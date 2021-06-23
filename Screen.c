#include "Screen.h"
#include <SDL.h>
#include <math.h>


void SDL_ExitWithError(const char *message) {
	SDL_Log("ERROR: %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void ScreenCreate(Screen *screen) {

  screen->window = NULL;
	screen->renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("can't initialize SDL");

	screen->window = SDL_CreateWindow("Planets simulator",
														SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // window left top corner position
														500, 500, // window size
														0); // mode = default
	if (screen->window == NULL)
		SDL_ExitWithError("can't initialize SDL window");

	screen->renderer = SDL_CreateRenderer(screen->window, -1, SDL_RENDERER_SOFTWARE);
	if (screen->renderer == NULL)
		SDL_ExitWithError("can't initialize renderer");

}

void ScreenRender(Screen *screen) {
  SDL_RenderPresent(screen->renderer);
}

void ScreenClose(Screen *screen) {

  SDL_DestroyRenderer(screen->renderer);
	SDL_DestroyWindow(screen->window);
	SDL_Quit();

}


void ScreenDrawPoint(Screen *screen, int x, int y) {
	if (SDL_RenderDrawPoint(screen->renderer, x, y) != 0)
		SDL_ExitWithError("can't draw point");
}


// Code get from the beginner guide : http://www.brainycode.com/downloads/LearningSDL011.pdf and adapted for this utilisation
void ScreenDrawCircle(Screen *screen, int x_center, int y_center, int initial_radius) {

	for (int radius = initial_radius; radius > 0; radius--) {

		int x, y, r2;
		r2 = radius * radius;

		for (int x = -radius; x <= radius; x++) {
			y = (int)sqrt(r2-x*x + 0.5);
			ScreenDrawPoint(screen, x_center + x, y_center + y);
			ScreenDrawPoint(screen, x_center + x, y_center - y);
		}

	}

}

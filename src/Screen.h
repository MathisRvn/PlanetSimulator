#include <SDL.h>

#ifndef SCREEN_H
  #define SCREEN_H

  typedef struct Screen {

    SDL_Window *window;
    SDL_Renderer * renderer;

  } Screen;

  void SDL_ExitWithError(const char *message);

  void ScreenCreate(Screen *screen);
  void ScreenRender(Screen *screen);
  void ScreenClose(Screen *screen);
  
  void ScreenDrawPoint(Screen *screen, int x, int y);
  void ScreenDrawCircle(Screen *screen, int x, int y, int radius);

#endif

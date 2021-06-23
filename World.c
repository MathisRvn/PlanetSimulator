#include "Object.h"
#include <SDL.h>


#include "World.h"

void WorldDrawWorld (Screen *screen, Object obj_list[], int object_number) {

  // Rendering on screen
  if (SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
    SDL_ExitWithError("can't draw color");

  if (SDL_RenderClear(screen->renderer) != 0)
    SDL_ExitWithError("can't clear renderer");

  if (SDL_SetRenderDrawColor(screen->renderer, 255, 168, 237, SDL_ALPHA_OPAQUE) != 0)
    SDL_ExitWithError("can't draw color");

  long double x_min = 0;
  long double x_max = 0;
  long double y_min = 0;
  long double y_max = 0;

  for (short a = 0; a < object_number; a++) {

    if (obj_list[a].position.x < x_min)
      x_min = obj_list[a].position.x;
    if (obj_list[a].position.x > x_max)
      x_max = obj_list[a].position.x;

    if (obj_list[a].position.y < y_min)
      y_min = obj_list[a].position.y;
    if (obj_list[a].position.y > y_max)
      y_max = obj_list[a].position.y;

  }

  long double ratio = 0;
  if (x_max-x_min>y_max-y_min)
    ratio = 400 / (x_max-x_min);
  else
    ratio = 400 / (y_max-y_min);

  if (ratio < 0)
    ratio = ratio * -1;

  for (short a = 0; a < object_number; a++) {
    int x = (int)((obj_list[a].position.x + fabs(x_min)) * ratio) + 50;
    int y = (int)((obj_list[a].position.y + fabs(y_min)) * ratio) + 50;
    ScreenDrawCircle(screen, x, y, 10);

  }

  ScreenRender(screen);
  SDL_Delay(10);
}

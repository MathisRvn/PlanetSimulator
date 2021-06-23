#include "Object.h"
#include <SDL.h>
#include "gravitationnalForce.h"


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

void WorldApplySpeed (Object obj_list[], long double delta_time, int object_number) {
  for (short a = 0; a < object_number; a++) {
    ObjectApplySpeed(&obj_list[a], delta_time);
  }
}


void WorldTick (Object obj_list[], long double delta_time, int object_number) {
  for (short a = 0; a < object_number; a++) {
    // for all object
    for (short b = 0; b < object_number; b++) {
      // for all object
      if (&obj_list[a] != &obj_list[b]) { // we check that the two object are not the same
        // We compute gravitationnal force
        Vec force = getGravitationnalForce(obj_list[a], obj_list[b]);
        ObjectApplyForce(&obj_list[a], force, delta_time);
      }
    }
  }
  WorldApplySpeed(obj_list, delta_time, object_number);
}

#include <stdio.h>
#include <SDL.h>
#include <math.h>


#include "Vec.h"
#include "Object.h"
#include "gravitationnalForce.h"
#include "Screen.h"


int main(int argc, char *argv[])
{

  Object earth = NEW_OBJ(6.9722E24);

  Object moon = NEW_OBJ(0.07346E24);
  moon.position.x = 384400 * 1000; // meters
  moon.speed.y = 1022; // meters per seconds

  #define object_number 2
  Object world[object_number] = {earth, moon};

  Screen screen;
  ScreenCreate(&screen);

  for (short i = 0; i < 1000; i++) {

    long double delta_time = 1000; // seconds

    for (short a = 0; a < object_number; a++) {

      // for all object

      for (short b = 0; b < object_number; b++) {

        // for all object

        if (&world[a] != &world[b]) { // we check that the two object are not the same

          // We compute gravitationnal force
          Vec force = getGravitationnalForce(world[a], world[b]);
          applyForce(&world[a], force, delta_time);

        }

      }

    }

    for (short a = 0; a < object_number; a++) {

      applySpeed(&world[a], delta_time);

    }

    // Rendering on screen
    if (SDL_SetRenderDrawColor(screen.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
  		SDL_ExitWithError("can't draw color");

    if (SDL_RenderClear(screen.renderer) != 0)
		  SDL_ExitWithError("can't clear renderer");

    if (SDL_SetRenderDrawColor(screen.renderer, 255, 168, 237, SDL_ALPHA_OPAQUE) != 0)
  		SDL_ExitWithError("can't draw color");

    long double x_min = 0;
    long double x_max = 0;
    long double y_min = 0;
    long double y_max = 0;

    for (short a = 0; a < object_number; a++) {

      if (world[a].position.x < x_min)
        x_min = world[a].position.x;
      if (world[a].position.x > x_max)
        x_max = world[a].position.x;

      if (world[a].position.y < y_min)
        y_min = world[a].position.y;
      if (world[a].position.y > y_max)
        y_max = world[a].position.y;

    }

    long double ratio = 0;
    if (x_max-x_min>y_max-y_min)
      ratio = 400 / (x_max-x_min);
    else
      ratio = 400 / (y_max-y_min);

    if (ratio < 0)
      ratio = ratio * -1;

    for (short a = 0; a < object_number; a++) {
      int x = (int)((world[a].position.x + fabs(x_min)) * ratio) + 50;
      int y = (int)((world[a].position.y + fabs(y_min)) * ratio) + 50;
      ScreenDrawCircle(&screen, x, y, 10);

    }

    ScreenRender(&screen);
    SDL_Delay(10);
  }

  ScreenClose(&screen);

  return 0;
}

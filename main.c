#include <stdio.h>
#include <SDL.h>
#include <math.h>


#include "Vec.h"
#include "Object.h"
#include "gravitationnalForce.h"
#include "Screen.h"
#include "World.h"


int main(int argc, char *argv[])
{

  Object earth = NEW_OBJ(6.9722E24);

  Object moon = NEW_OBJ(0.07346E24);
  moon.position.x = 384400 * 1000; // meters
  moon.speed.y = 1022; // meters per seconds

  #define object_number 2
  Object obj_list[object_number] = {earth, moon};

  Screen screen;
  ScreenCreate(&screen);

  for (short i = 0; i < 1000; i++) {

    long double delta_time = 1000; // seconds

    for (short a = 0; a < object_number; a++) {

      // for all object

      for (short b = 0; b < object_number; b++) {

        // for all object

        if (&obj_list[a] != &obj_list[b]) { // we check that the two object are not the same

          // We compute gravitationnal force
          Vec force = getGravitationnalForce(obj_list[a], obj_list[b]);
          applyForce(&obj_list[a], force, delta_time);

        }

      }

    }

    for (short a = 0; a < object_number; a++) {

      applySpeed(&obj_list[a], delta_time);

    }

    WorldDrawWorld(&screen, obj_list, object_number);
  }

  ScreenClose(&screen);

  return 0;
}

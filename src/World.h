#include "Object.h"
#include "Screen.h"

#ifndef WORLD_H
  #define WORLD_H

  void WorldApplySpeed (Object obj_list[], long double delta_time, int object_number);
  void WorldTick (Object obj_list[], long double delta_time, int object_number);
  void WorldDrawWorld (Screen *screen, Object obj_list[], int object_number);

#endif

#include "Vec.h"

#ifndef OBJECT_H
  #define OBJECT_H

  typedef struct Object {

    Vec position;
    Vec speed;
    long double mass;

  } Object;

  Object NEW_OBJ(long double mass);
  void applySpeed(Object *obj, long double delta_time);
  void applyForce (Object *obj, Vec force, long double delta_time);

#endif

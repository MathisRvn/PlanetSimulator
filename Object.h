#include "Vec.h"

#ifndef OBJECT_H
  #define OBJECT_H

  typedef struct Object {

    Vec position;
    Vec speed;
    long double mass;

  } Object;

  Object NEW_OBJ(long double mass);
  void ObjectApplySpeed(Object *obj, long double delta_time);
  void ObjectApplyForce (Object *obj, Vec force, long double delta_time);

#endif

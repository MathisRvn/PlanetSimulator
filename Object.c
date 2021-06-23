#include "Object.h"

Object NEW_OBJ(long double mass) {
  Object obj;
  NEW_VEC(obj_pos);
  obj.position = obj_pos;
  NEW_VEC(obj_speed);
  obj.speed = obj_speed;
  obj.mass = mass;
  return obj;
}

void ObjectApplySpeed(Object *obj, long double delta_time) {
  // position += speed * delta_time
  obj->position = VecAdd(obj->position, VecMul(obj->speed, delta_time));
}

void ObjectApplyForce (Object *obj, Vec force, long double delta_time) {
  // delta_speed = force * delta_time / mass
  Vec delta_speed = VecMul(force, (delta_time/obj->mass));
  obj->speed = VecAdd(obj->speed, delta_speed);
}

#include "Object.h"
#include "Vec.h"

#include "gravitationnalForce.h"

Vec getGravitationnalForce(Object obj1, Object obj2) {

  Vec deplacementVec = VecSub(obj2.position, obj1.position);
  long double distance = VecGetLength( deplacementVec );
  long double force_length = GRAVITATIONNAL_CONSTANT * obj1.mass * obj2.mass / (distance*distance);
  Vec force = VecGenerateColinear(deplacementVec, force_length);

  return force;

}

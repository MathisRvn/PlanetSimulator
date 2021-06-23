#include "Vec.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

Vec VecAdd (Vec vec1, Vec vec2) {
  Vec out;
  out.x = vec1.x + vec2.x;
  out.y = vec1.y + vec2.y;
  out.z = vec1.z + vec2.z;
  return out;
}

Vec VecSub (Vec vec1, Vec vec2) {
  Vec out;
  out.x = vec1.x - vec2.x;
  out.y = vec1.y - vec2.y;
  out.z = vec1.z - vec2.z;
  return out;
}

Vec VecMul (Vec vec1, long double nb) {
  Vec out;
  out.x = vec1.x * nb;
  out.y = vec1.y * nb;
  out.z = vec1.z * nb;
  return out;
}

long double VecGetLength(Vec vec) {
  return sqrt( vec.x*vec.x + vec.y*vec.y + vec.z*vec.z );
}

bool VecEqual (Vec vec1, Vec vec2) {
  if (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z) {
    return true;
  }else{
    return false;
  }
}

Vec VecGenerateColinear (Vec colinear_vector, long double vector_length) {
  long double k = vector_length / VecGetLength(colinear_vector);
  return VecMul(colinear_vector, k);
}

void printVec (Vec vec) {
  printf("Vec(%Lf %Lf %Lf)\n", vec.x, vec.y, vec.z);
}

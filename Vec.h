#ifndef VEC_H
  #define VEC_H

  typedef struct Vec {

    long double x;
    long double y;
    long double z;

  } Vec;

  #define NEW_VEC(X) Vec X = {0, 0, 0}

  Vec VecAdd (Vec vec1, Vec vec2);
  Vec VecSub (Vec vec1, Vec vec2);
  Vec VecMul (Vec vec1, long double nb);
  long double VecGetLength(Vec vec);
  Vec VecGenerateColinear (Vec colinear_vector, long double vector_length);
  void printVec (Vec vec);

#endif
